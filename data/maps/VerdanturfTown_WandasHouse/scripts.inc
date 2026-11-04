VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
#if GERMAN
	.string "Heiko: Ich habe gegen dich verloren,\n"
	.string "{PLAYER}. Aber das betrübt mich nicht.\p"
	.string "Ich habe ein neues Ziel in meinem Leben.\n"
	.string "Zusammen mit meinem Pokémon mache\p"
	.string "ich mich auf, die Arenen\n"
	.string "herauszufordern und ein großer Trainer\l"
	.string "zu werden.\p"
	.string "Behalte mich ruhig im Auge, {PLAYER}.\n"
	.string "Bald bin ich stärker als du!\p"
	.string "Und dann werde ich dich zu einem neuen\n"
	.string "Kampf herausfordern.$"
#else
	.string "WALLY: I lost to you, {PLAYER}, but I'm\n"
	.string "not feeling down anymore.\p"
	.string "Because I have a new purpose in life.\n"
	.string "Together with my POKéMON, I'm going\l"
	.string "to challenge POKéMON GYMS and become\l"
	.string "a great TRAINER.\p"
	.string "Please watch me, {PLAYER}.\n"
	.string "I'm going to be stronger than you.\p"
	.string "When I do, I'm going to challenge you\n"
	.string "to another battle.$"
#endif

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
#if GERMAN
	.string "Heiko: Behalte mich ruhig im Auge,\n"
	.string "{PLAYER}. Bald bin ich stärker als du!\p"
	.string "Und dann werde ich dich zu einem neuen\n"
	.string "Kampf herausfordern.$"
#else
	.string "WALLY: Please watch me, {PLAYER}.\n"
	.string "I'm going to get stronger than you.\p"
	.string "When I do, I'm going to challenge you\n"
	.string "to another battle.$"
#endif

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
#if GERMAN
	.string "Onkel: Oh! {PLAYER}{KUN}!\n"
	.string "Du findest Heiko nebenan.\p"
	.string "Aber es gibt etwas, das ich dir sagen\n"
	.string "muss.\p"
	.string "Diese natürliche Umgebung hat Wunder\n"
	.string "gewirkt bei Heikos Gesundheit.\p"
	.string "Und nicht nur die natürliche Umgebung!\n"
	.string "Ich denke, auch die Freundschaft zu\l"
	.string "den Pokémon hat ihm geholfen…$"
#else
	.string "UNCLE: Oh! {PLAYER}{KUN}!\n"
	.string "WALLY's next door.\p"
	.string "But, boy, there's something I have to\n"
	.string "tell you.\p"
	.string "This natural environment is doing\n"
	.string "wonders for WALLY's health.\p"
	.string "Maybe it's not just the environment.\n"
	.string "It could be POKéMON that are giving\l"
	.string "the boy hope.$"
#endif

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
#if GERMAN
	.string "Heiko ist weggegangen…\n"
	.string "Er ist nun auf seinem eigenen Weg…$"
#else
	.string "WALLY's gone away…\n"
	.string "He slipped off on his own…$"
#endif

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
#if GERMAN
	.string "Onkel: Stimmt das?\n"
	.string "Heiko ist ganz alleine in die Welt\l"
	.string "hinausgezogen…\p"
	.string "Ich sollte ihn unterstützen - er ist\n"
	.string "der Sohn meines kleinen Bruders…$"
#else
	.string "UNCLE: Is that right?\n"
	.string "WALLY's gone away that far all by\l"
	.string "himself…\p"
	.string "Well, I have to give him credit--he is\n"
	.string "my little brother's son.$"
#endif

VerdanturfTown_WandasHouse_Text_MeetWanda:
#if GERMAN
	.string "Heike: Wer bist du?\n"
	.string "Oh, ja, ich weiß schon…\p"
	.string "Du bist {PLAYER}. Heiko hat mir schon\n"
	.string "viel von dir erzählt.\p"
	.string "Ich bin Heikos Cousine.\n"
	.string "Nett, dich kennen zu lernen!\p"
	.string "Ich finde, seit Heiko hier lebt, ist er\n"
	.string "viel gesünder und lebendiger geworden.$"
#else
	.string "WANDA: You are?\n"
	.string "Oh, right, I get it!\p"
	.string "You're the {PLAYER} who WALLY was\n"
	.string "telling me about.\p"
	.string "I'm WALLY's cousin.\n"
	.string "Glad to meet you!\p"
	.string "I think WALLY's become a lot more lively\n"
	.string "and healthy since he came here.$"
#endif

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
#if GERMAN
	.string "Heike: Mach dir keine Sorgen um Heiko.\n"
	.string "Ihm geht es mit Sicherheit gut.\p"
	.string "Ich kenne doch meinen kleinen Vetter.\n"
	.string "Außerdem hat er sein Pokémon dabei.$"
#else
	.string "WANDA: Don't worry about WALLY.\n"
	.string "He'll be just fine.\p"
	.string "I know my little cousin, and he has\n"
	.string "POKéMON with him, too.$"
#endif

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
#if GERMAN
	.string "Dank dir kann ich meine Freundin jetzt\n"
	.string "jeden Tag sehen. Ob ich glücklich bin?\l"
	.string "Darauf kannst du wetten!$"
#else
	.string "Thanks to you, I can see my girlfriend\n"
	.string "every day.\l"
	.string "Happy? You bet I am!$"
#endif

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
#if GERMAN
	.string "Der Freund meiner Tochter besitzt viel\n"
	.string "Schwung und Energie.\p"
	.string "Er gräbt ununterbrochen einen Tunnel,\n"
	.string "damit er meine Tochter sehen kann.\p"
	.string "Meine Tochter ist etwas besorgt des-\n"
	.string "wegen und schaut jeden Tag nach ihm.$"
#else
	.string "My daughter's boyfriend is a very\n"
	.string "driven and passionate sort of person.\p"
	.string "He's been digging a tunnel nonstop\n"
	.string "just so he can see my daughter.\p"
	.string "My daughter's a little concerned,\n"
	.string "so she goes out to the tunnel a lot.$"
#endif

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
#if GERMAN
	.string "Es ist unglaublich! Der Freund meiner\n"
	.string "Tochter hat den Tunnel\p"
	.string "von Hand gegraben! Einfach sagenhaft!$"
#else
	.string "It's amazing. My daughter's boyfriend\n"
	.string "was digging the tunnel by hand!\p"
	.string "It's so incredible!$"
#endif

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
#if GERMAN
	.string "Sollte Heiko irgendetwas passieren,\n"
	.string "könnte ich seinen Eltern in Blütenburg\l"
	.string "City nicht mehr in die Augen schauen…$"
#else
	.string "If anything were to happen to WALLY,\n"
	.string "I would never be able to look his\l"
	.string "parents in PETALBURG in the eye…$"
#endif

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
#if GERMAN
	.string "Heiko war in Prachtpolis City?\p"
	.string "Seine Eltern in Blütenburg City werden\n"
	.string "erstaunt sein, das zu hören.$"
#else
	.string "WALLY was in EVER GRANDE?\p"
	.string "His parents in PETALBURG would be\n"
	.string "astonished to hear that!$"
#endif

