MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
#if IS_HNS
	@ HnS: no handover, the Rock Smash license comes with the Dynamo Badge.
	msgbox Text_HnsRockSmashDudeNoHandover, MSGBOX_DEFAULT
#else
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
#endif
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
#if !IS_HNS
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
#endif
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
#if GERMAN
	.string "Woohoo!\p"
	.string "Die Leute nennen mich den Zertrümmerer,\n"
	.string "aber ich finde den Namen unter meinem\l"
	.string "Niveau!\p"
	.string "Ich verdiene doch wohl etwas mehr\n"
	.string "Respekt! Man sollte mich\l"
	.string "Zertrümmerer-Meister nennen!\p"
	.string "Woohoo, deine Pokémon sehen wirklich\n"
	.string "sehr stark aus.\p"
	.string "Das sehe ich gerne!\n"
	.string "Hier, nimm diese VM!$"
#else
	.string "Woohoo!\p"
	.string "I hear people call me the ROCK SMASH\n"
	.string "GUY, but I find that sort of degrading.\p"
	.string "I think I deserve a bit more respect,\n"
	.string "like maybe the ROCK SMASH DUDE.\p"
	.string "Woohoo!\p"
	.string "Anyways, your POKéMON look pretty\n"
	.string "strong.\p"
	.string "I like that!\n"
	.string "Here, take this HIDDEN MACHINE!$"
#endif

MauvilleCity_House1_Text_ExplainRockSmash:
#if GERMAN
	.string "Diese VM enthält Zertrümmerer.\p"
	.string "Wenn du unterwegs auf große\n"
	.string "Felsbrocken stößt…\p"
	.string "Dann nutze diese VM, um dir den Weg\n"
	.string "freizumachen.\p"
	.string "Jawohl! Zertrümmert Hindernisse, das\n"
	.string "ist meine Devise. Woohoo!$"
#else
	.string "That HM contains ROCK SMASH.\p"
	.string "If you come across large boulders\n"
	.string "that block your path…\p"
	.string "Well, use that HM move and smash\n"
	.string "them right out of your way!\p"
	.string "Yes, sir! Smash rocks aside, I say!\n"
	.string "Woohoo!$"
#endif

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
#if GERMAN
	.string "Oh ja, wenn du einen Felsen\n"
	.string "zertrümmerst, könnte ein Pokémon zum\l"
	.string "Vorschein kommen.\p"
	.string "Woohoo!$"
#else
	.string "Oh, yes, if you smash a rock, a POKéMON\n"
	.string "could come flying out of hiding.\p"
	.string "Woohoo!$"
#endif

#if IS_HNS
@ Unused.
Text_HnsRockSmashLicense:
#if GERMAN
	.string "{PLAYER} erhält die Lizenz für\n"
	.string "Zertrümmerer!$"
#else
	.string "{PLAYER} received the licence for\n"
	.string "ROCK SMASH!$"
#endif

Text_HnsRockSmashDudeNoHandover:
#if GERMAN
	.string "Woohoo!\p"
	.string "Die Leute nennen mich den Zertrümmerer,\n"
	.string "aber ich finde den Namen unter meinem\l"
	.string "Niveau!\p"
	.string "Ich verdiene doch wohl etwas mehr\n"
	.string "Respekt! Man sollte mich\l"
	.string "Zertrümmerer-Meister nennen!\p"
	.string "Ich zertrümmere alles!\p"
	.string "Und wie ich sehe, hast du die\n"
	.string "VM Zertrümmerer selbst dabei.\p"
	.string "Aber bedenke: In Hoenn darf man sie\n"
	.string "nur einsetzen, wenn man Walters\l"
	.string "Dynamo-Orden hat. Woohoo!$"
#else
	.string "Woohoo!\p"
	.string "I hear people call me the ROCK SMASH\n"
	.string "GUY, but I find that sort of degrading.\p"
	.string "I think I deserve a bit more respect,\n"
	.string "like maybe the ROCK SMASH DUDE.\p"
	.string "Woohoo!\p"
	.string "I smash everything!\p"
	.string "And I see you carry HM ROCK SMASH\n"
	.string "yourself.\p"
	.string "But remember: in HOENN you may only\n"
	.string "use it once you have WATTSON's\l"
	.string "DYNAMO BADGE. Woohoo!$"
#endif
#endif
