Route34_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route34_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route34_OnTransition:
	specialvar VAR_RESULT, GetDaycareState
	call_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_MapScript_EggReady
	callnative SetTimeBasedEncounters
	end

Route34_MapScript_EggReady::
	setobjectxyperm LOCALID_ROUTE34_DAYCAREMAN, 30, 34
	return

Route34_EventScript_YoungsterSamuel::
	trainerbattle_single TRAINER_SAMUEL_HNS, Route34_Text_YoungsterSamuel_Seen, Route34_Text_YoungsterSamuel_Beaten
	msgbox Route34_Text_YoungsterSamuel_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_YoungsterIan::
	trainerbattle_single TRAINER_IAN_HNS, Route34_Text_YoungsterIan_Seen, Route34_Text_YoungsterIan_Beaten
	msgbox Route34_Text_YoungsterIan_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_CamperTodd::
	trainerbattle_single TRAINER_TODD_HNS, Route34_Text_CamperTodd_Seen, Route34_Text_CamperTodd_Beaten, Route34_EventScript_RegisterTodd
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchTodd
	msgbox Route34_Text_CamperTodd_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterTodd::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_ToddRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TODD_HNS
	release
	end

Route34_EventScript_RematchTodd::
	trainerbattle_rematch TRAINER_TODD_HNS, Route34_Text_ToddRematchIntro, Route34_Text_ToddRematchDefeat
	msgbox Route34_Text_ToddPostRematch, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_PicnickerGina::
	trainerbattle_single TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten, Route34_EventScript_RegisterGina
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route34_EventScript_RematchGina
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_RegisterGina::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route34_Text_GinaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GINA_HNS
	release
	end

Route34_EventScript_RematchGina::
	trainerbattle_rematch TRAINER_GINA_HNS, Route34_Text_PicnickerGina_Seen, Route34_Text_PicnickerGina_Beaten
	msgbox Route34_Text_PicnickerGina_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_OfficerKeith::
	trainerbattle_single TRAINER_KEITH_HNS, Route34_Text_OfficerKeith_Seen, Route34_Text_OfficerKeith_Win
	msgbox Route34_Text_OfficerKeith_After, MSGBOX_AUTOCLOSE
	end


Route34_EventScript_PokefanMBrandon::
	trainerbattle_single TRAINER_BRANDON_HNS, Route34_Text_PokefanBrandon_Seen, Route34_Text_PokefanBrandon_Beaten
	msgbox Route34_Text_PokefanBrandon_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Irene::
	trainerbattle_single TRAINER_IRENE_HNS, Route34_Text_CooltrainerIrene_Seen, Route34_Text_CooltrainerIrene_Beaten
	msgbox Route34_Text_CooltrainerIrene_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Jenn::
	trainerbattle_single TRAINER_JENN_HNS, Route34_Text_CooltrainerJenn_Seen, Route34_Text_CooltrainerJenn_Beaten
	msgbox Route34_Text_CooltrainerJenn_After2, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Kate::
	trainerbattle_single TRAINER_KATE_HNS, Route34_Text_CooltrainerKate_Seen, Route34_Text_CooltrainerKate_Beaten
	msgbox Route34_Text_CooltrainerKate_After, MSGBOX_AUTOCLOSE
	end

Route34_EventScript_Sign1::
	lock
	msgbox Route34_Text_Sign_Route34, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign2::
	lock
	msgbox Route34_Text_Sign_DayCare, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Sign3::
	lock
	msgbox Route34_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route34_EventScript_Item_SoftSand::
	finditem ITEM_SOFT_SAND
	end

Route34_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

Route34_EventScript_Item_Embargo::
    finditem ITEM_TM_EMBARGO
    end


Route34_Text_YoungsterSamuel_Seen:
#if GERMAN
	.string "Hier trainiere ich!$"
#else
	.string "Hey! I'm looking for MANKEY!$"
#endif

Route34_Text_YoungsterSamuel_Beaten:
#if GERMAN
	.string "Besiegt von einem Passanten!$"
#else
	.string "Beaten by a passing stranger!$"
#endif

Route34_Text_YoungsterSamuel_After:
#if GERMAN
	.string "Ich werde noch härter trainieren.\p"
	.string "Ich möchte doch ein Arenaleiter werden.$"
#else
	.string "I'm going to train even harder.\p"
	.string "After all, I'm trying to become\n"
	.string "a GYM LEADER.$"
#endif

Route34_Text_YoungsterIan_Seen:
#if GERMAN
	.string "In meiner Klasse bin ich der\n"
	.string "Pokémon-Experte!$"
#else
	.string "I'm the best in my class at\n"
	.string "POKéMON.$"
#endif

Route34_Text_YoungsterIan_Beaten:
#if GERMAN
	.string "Neiiin! Aber na gut, jeder findet wohl\n"
	.string "irgendwann einmal seinen Meister.$"
#else
	.string "No! There are better trainers…$"
#endif

Route34_Text_YoungsterIan_After:
#if GERMAN
	.string "Ich strenge mich sehr an, damit ich\n"
	.string "der Star in meiner Klasse bin.$"
#else
	.string "I'm trying hard so I can be the\n"
	.string "star in my class.$"
#endif

Route34_Text_CamperTodd_Seen:
#if GERMAN
	.string "Ich vertraue meinen Fähigkeiten als\n"
	.string "Trainer. Möchtest du dich überzeugen?$"
#else
	.string "I'm confident in my ability to\n"
	.string "raise POKéMON.\p"
	.string "Want to see?$"
#endif

Route34_Text_CamperTodd_Beaten:
#if GERMAN
	.string "Habe ich falsch trainiert?$"
#else
	.string "Did I screw up my training?$"
#endif

Route34_Text_CamperTodd_After:
#if GERMAN
	.string "Vielleicht sollte eines zur Pension..$"
#else
	.string "Maybe I should take one to DAY-CARE,\n"
	.string "or maybe use some items…$"
#endif

Route34_Text_ToddRegister:
#if GERMAN
    .string "Vielleicht sollte ich eines in die\n"
    .string "Pension bringen oder ein paar Items\l"
    .string "einsetzen…$"
#else
	.string "Maybe I should take one to DAY-CARE,\n"
	.string "or maybe use some items…$"
#endif

Route34_Text_ToddRematchIntro:
#if GERMAN
	.string "Ich vertraue meinen Fähigkeiten als\n"
	.string "Trainer. Möchtest du dich überzeugen?$"
#else
	.string "I'm confident in my ability to\n"
	.string "raise POKéMON.\p"
	.string "Want to see?$"
#endif

Route34_Text_ToddRematchDefeat:
#if GERMAN
    .string "Habe ich beim Training etwas falsch\n"
    .string "gemacht?$"
#else
	.string "Did I screw up my training?$"
#endif

Route34_Text_ToddPostRematch:
#if GERMAN
    .string "Vielleicht sollte ich eines in die\n"
    .string "Pension bringen oder ein paar Items\l"
    .string "einsetzen…$"
#else
	.string "Maybe I should take one to DAY-CARE,\n"
	.string "or maybe use some items…$"
#endif

Route34_Text_GinaRegister:
#if GERMAN
	.string "Du bist zu stark für einen\n"
	.string "Übungskampf.$"
#else
	.string "You're too strong to be a\n"
	.string "practice partner.$"
#endif

Route34_Text_PicnickerGina_Seen:
#if GERMAN
	.string "Bist du ein Trainer?\n"
	.string "Hast du Lust auf einen Übungskampf?$"
#else
	.string "Are you a TRAINER?\p"
	.string "Let's have a practice battle.$"
#endif

Route34_Text_PicnickerGina_Beaten:
#if GERMAN
	.string "Oh nein! Ich habe noch nie gewonnen…$"
#else
	.string "Oh, no! I just can't win…$"
#endif

Route34_Text_PicnickerGina_After:
#if GERMAN
	.string "Du bist mir zu stark.\n"
	.string "Das ist keine Übung für mich.$"
#else
	.string "You're too strong to be a\n"
	.string "practice partner.$"
#endif

Route34_Text_OfficerKeith_Seen:
#if GERMAN
	.string "Wer ist da? Was ist dein Begehr?$"
#else
	.string "Who goes there?\n"
	.string "What are you up to?$"
#endif

Route34_Text_OfficerKeith_Win:
#if GERMAN
	.string "Du bist ein starker, junger Gegner.$"
#else
	.string "You're a tough little kid.$"
#endif

Route34_Text_OfficerKeith_After:
#if GERMAN
	.string "Ja, heute scheint alles in Ordnung\n"
	.string "zu sein.\p"
	.string "Benimm dich und halte dich aus\n"
	.string "Schwierigkeiten heraus.$"
#else
	.string "Yep, nothing wrong today.\p"
	.string "Be good and stay out of trouble.$"
#endif

Route34_Text_OfficerKeith_Daytime:
#if GERMAN
	.string "Ich bin auf der Suche nach\n"
	.string "verdächtigen Individuen.$"
#else
	.string "I'm on patrol for suspicious\n"
	.string "individuals.$"
#endif

Route34_Text_PokefanBrandon_Seen:
#if GERMAN
	.string "Ich habe gerade mein Pokémon\n"
	.string "aus der Pension abgeholt.\p"
	.string "Sehen wir mal, wie stark es geworden\n"
	.string "ist!$"
#else
	.string "I just got my POKéMON back from\n"
	.string "DAY-CARE.\p"
	.string "Let's see how much stronger it got!$"
#endif

Route34_Text_PokefanBrandon_Beaten:
#if GERMAN
	.string "Warum muss es auf diese Weise enden?$"
#else
	.string "Why does it end this way?$"
#endif

Route34_Text_PokefanBrandon_After:
#if GERMAN
	.string "Mein Pokémon kannte Attacken, von\n"
	.string "denen ich nicht wusste, dass es sie hat.\p"
	.string "Das war überaus erstaunlich!$"
#else
	.string "My POKéMON came back with new moves.\p"
	.string "That confounded me to no end!$"
#endif

Route34_Text_Sign_IlexForest:
#if GERMAN
	.string "Direkt hinter dem Tor liegt\n"
	.string "der Steineichenwald.$"
#else
	.string "ILEX FOREST\n"
	.string "THROUGH THE GATE$"
#endif

Route34_Text_Sign_Route34:
#if GERMAN
	.string "Route 34\n"
	.string "Dukatia City - Azalea City\p"
	.string "Steineichenwald dazwischen$"
#else
	.string "ROUTE 34\n"
	.string "GOLDENROD CITY - AZALEA TOWN\p"
	.string "ILEX FOREST SOMEWHERE BETWEEN$"
#endif

Route34_Text_TrainerTips:
#if GERMAN
	.string "Tipps für Trainer\p"
	.string "Bäume mit Beeren\n"
	.string "tragen jeden Tag neue Beeren.\p"
	.string "Merke dir, welche Beeren\n"
	.string "an den Bäumen wachsen.$"
#else
	.string "TRAINER TIPS\p"
	.string "BERRY trees grow new BERRIES\n"
	.string "several times a day.\p"
	.string "Note which trees bear which\n"
	.string "BERRIES.$"
#endif

Route34_Text_CooltrainerIrene_Seen:
#if GERMAN
	.string "Lola: Hey, Augenblick mal!\n"
	.string "Wer bist du?!$"
#else
	.string "IRENE: Who are you?!$"
#endif

Route34_Text_CooltrainerIrene_Beaten:
#if GERMAN
	.string "Lola: Oooh!\n"
	.string "Du hast mich umgehauen!$"
#else
	.string "IRENE: Ohhh! You're too strong!$"
#endif

Route34_Text_CooltrainerIrene_After1:
#if GERMAN
	.string "Lola: Warte ab, bis du meine Schwester\n"
	.string "Edna kennenlernst!$"
#else
	.string "IRENE: My sister KATE will get you\n"
	.string "for this!$"
#endif

Route34_Text_CooltrainerIrene_After2:
#if GERMAN
	.string "Lola: Ist dieser Strand nicht herrlich?\p"
	.string "Er ist unsere geheime Zuflucht!$"
#else
	.string "IRENE: Isn't this beach great?\p"
	.string "It's our secret little getaway!$"
#endif

Route34_Text_CooltrainerJenn_Seen:
#if GERMAN
	.string "Else: Hey, Augenblick mal!\n"
	.string "Was willst du hier?!$"
#else
	.string "JENN: What the...?\n"
	.string "What are you doing?$"
#endif

Route34_Text_CooltrainerJenn_Beaten:
#if GERMAN
	.string "Else: Es tut mir so leid, Schwesterchen!$"
#else
	.string "JENN: So sorry, IRENE! Dear Sis!$"
#endif

Route34_Text_CooltrainerJenn_After1:
#if GERMAN
	.string "Else: Bilde dir bloß nichts ein!\n"
	.string "Meine Schwester Edna ist sehr stark!$"
#else
	.string "JENN: Don't get cocky! My sister\n"
	.string "KATE is tough!$"
#endif

Route34_Text_CooltrainerJenn_After2:
#if GERMAN
	.string "Else: Sonnenlicht kräftigt deinen\n"
	.string "Körper.$"
#else
	.string "JENN: Sunlight makes your body\n"
	.string "stronger.$"
#endif

Route34_Text_CooltrainerKate_Seen:
#if GERMAN
	.string "Edna: Du warst gemein zu meinen kleinen\n"
	.string "Schwestern!$"
#else
	.string "KATE: I must pay you back for\n"
	.string "taking care of my sisters!$"
#endif

Route34_Text_CooltrainerKate_Beaten:
#if GERMAN
	.string "Edna: Nein! Ich kann nicht glauben,\n"
	.string "dass ich verloren habe.$"
#else
	.string "KATE: No! I can't believe I lost.$"
#endif

Route34_Text_CooltrainerKate_GiveSoftSand:
#if GERMAN
	.string "Edna: Du bist zu stark. Ich hatte\n"
	.string "keine Chance.\p"
	.string "Hier. Das hast du dir verdient.$"
#else
	.string "KATE: You are so strong.\n"
	.string "We lost with no excuses...\p"
	.string "Here, take this!$"
#endif

Route34_Text_CooltrainerKate_After:
#if GERMAN
	.string "Edna: Tut mir leid, dass ich dich aus\n"
	.string "heiterem Himmel angegriffen habe.\p"
	.string "Ich dachte eigentlich, wir wären hier\n"
	.string "unter uns, und bin deshalb ein bisschen\l"
	.string "erschrocken.$"
#else
	.string "KATE: I'm sorry we jumped you.\p"
	.string "We never expected anyone to find\n"
	.string "us here. You sure startled us.$"
#endif


Route34_Text_Sign_DayCare:
#if GERMAN
	.string "Pension\p"
	.string "Wir kümmern uns um deine Pokémon!$"
#else
	.string "DAY-CARE\p"
	.string "LET US RAISE YOUR POKéMON FOR YOU!$"
#endif
