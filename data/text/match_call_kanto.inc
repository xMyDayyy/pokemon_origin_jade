@ Kanto PokeCom call texts (60 phone trainers).
@ Per trainer: Battle (armed rematch, names the route) and one personal
@ General; per class two shared Generals (src/match_call.c, HNS_MC_CLASS).

@ Teenager Egon (TRAINER_YOUNGSTER_BEN), MAP_ROUTE3
MatchCall_Kanto_Ben_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Egon.\p"
	.string "Ich trage immer noch Shorts! Auch\n"
	.string "zwischen den Brennnesseln!\p"
	.string "Komm zu Route 3 und kämpf mit mir!$"
#else
	.string "Hey, {PLAYER}! It's BEN.\p"
	.string "I'm still wearing shorts! They're so\n"
	.string "comfy!\p"
	.string "Come to ROUTE 3 and battle me!$"
#endif

MatchCall_Kanto_Ben_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Egon.\p"
	.string "Mein {STR_VAR_3} hat sich in den\n"
	.string "Brennnesseln versteckt.\p"
	.string "Und ich in Shorts hinterher… Autsch!$"
#else
	.string "Hey, {PLAYER}! It's BEN.\p"
	.string "My {STR_VAR_3} hid in the tall grass.\p"
	.string "And I went after it in shorts… Ouch!$"
#endif

@ Käfersammler Attila (TRAINER_BUG_CATCHER_COLTON), MAP_ROUTE3
MatchCall_Kanto_Colton_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Attila!\p"
	.string "Weißt du noch? Wir kennen uns aus dem\n"
	.string "Vertania-Wald!\p"
	.string "Meine Käfer sind jetzt stärker. Komm zu\n"
	.string "Route 3!$"
#else
	.string "Hey, {PLAYER}! It's COLTON!\p"
	.string "Remember? I saw you in\n"
	.string "VIRIDIAN FOREST!\p"
	.string "My bugs are tougher now. Come to\n"
	.string "ROUTE 3!$"
#endif

MatchCall_Kanto_Colton_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Attila.\p"
	.string "Ich hab heute ein Pokémon gesehen, das\n"
	.string "es im Wald gar nicht gibt!\p"
	.string "Mein {STR_VAR_3} hat sich total\n"
	.string "erschrocken!$"
#else
	.string "Hey, {PLAYER}! It's COLTON.\p"
	.string "Today I saw a POKéMON you don't find in\n"
	.string "forests!\p"
	.string "My {STR_VAR_3} got a real fright!$"
#endif

@ Göre Ricarda (TRAINER_LASS_JANICE), MAP_ROUTE3
MatchCall_Kanto_Janice_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Ricarda.\p"
	.string "Starrst du gerade wieder jemanden an?\n"
	.string "Dann starr lieber mich an!\p"
	.string "Ich warte auf Route 3!$"
#else
	.string "Hi, {PLAYER}! It's JANICE.\p"
	.string "Are you staring at someone again?\n"
	.string "Stare at me instead!\p"
	.string "I'm waiting on ROUTE 3!$"
#endif

MatchCall_Kanto_Janice_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Ricarda.\p"
	.string "Heute hat mich ein Junge angestarrt.\n"
	.string "Mein {STR_VAR_3} hat ihn verjagt!\p"
	.string "Selbst schuld!$"
#else
	.string "Hi, {PLAYER}! It's JANICE.\p"
	.string "A boy stared at me today. My\n"
	.string "{STR_VAR_3} chased him off!\p"
	.string "Serves him right!$"
#endif

@ Göre Adelheid (TRAINER_LASS_CRISSY), MAP_ROUTE4
MatchCall_Kanto_Crissy_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Adelheid.\p"
	.string "Ich hab am Mondberg wieder\n"
	.string "Pilz-Pokémon gefangen!\p"
	.string "Komm zu Route 4, dann zeig ich sie dir!$"
#else
	.string "Hi, {PLAYER}! It's CRISSY.\p"
	.string "I caught more mushroom POKéMON on\n"
	.string "MT. MOON!\p"
	.string "Come to ROUTE 4 and I'll show you!$"
#endif

MatchCall_Kanto_Crissy_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Adelheid.\p"
	.string "Mein {STR_VAR_3} hat heute wieder\n"
	.string "Pilze gesammelt.\p"
	.string "Ich glaube, es liebt den Mondberg\n"
	.string "genauso wie ich!$"
#else
	.string "Hi, {PLAYER}! It's CRISSY.\p"
	.string "My {STR_VAR_3} gathered mushrooms\n"
	.string "again today.\p"
	.string "I think it loves MT. MOON as much as I\n"
	.string "do!$"
#endif

@ Teenager Frieder (TRAINER_YOUNGSTER_TIMMY), MAP_ROUTE24
MatchCall_Kanto_Timmy_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Frieder!\p"
	.string "Du liebst doch die Nuggetbrücke, oder?\p"
	.string "Dann komm zu Route 24! Ich mache dir\n"
	.string "das Leben schwer!$"
#else
	.string "Hey, {PLAYER}! It's TIMMY!\p"
	.string "You love NUGGET BRIDGE, don't you?\p"
	.string "Then come to ROUTE 24! I won't be easy!$"
#endif

MatchCall_Kanto_Timmy_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Frieder.\p"
	.string "Heute sind fünf Trainer über die\n"
	.string "Nuggetbrücke gekommen.\p"
	.string "Mein {STR_VAR_3} hat alle\n"
	.string "aufgehalten! Na ja, fast alle…$"
#else
	.string "Hey, {PLAYER}! It's TIMMY.\p"
	.string "Five TRAINERS came over NUGGET BRIDGE\n"
	.string "today.\p"
	.string "My {STR_VAR_3} stopped them all! Well,\n"
	.string "almost all…$"
#endif

@ Göre Una (TRAINER_LASS_RELI), MAP_ROUTE24
MatchCall_Kanto_Reli_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Una.\p"
	.string "Du bist bestimmt wieder total\n"
	.string "beschäftigt… Wirst du nicht müde?\p"
	.string "Mach doch eine Pause auf Route 24! Mit\n"
	.string "einem Kampf!$"
#else
	.string "Hi, {PLAYER}! It's RELI.\p"
	.string "I bet you're busy again… Aren't you\n"
	.string "getting tired?\p"
	.string "Take a break on ROUTE 24! With a battle!$"
#endif

MatchCall_Kanto_Reli_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Una.\p"
	.string "Ich bin heute zehnmal über die\n"
	.string "Nuggetbrücke gelaufen.\p"
	.string "Jetzt bin ich müde. Und mein\n"
	.string "{STR_VAR_3} schläft schon!$"
#else
	.string "Hi, {PLAYER}! It's RELI.\p"
	.string "I walked across NUGGET BRIDGE ten\n"
	.string "times today.\p"
	.string "Now I'm tired. And my {STR_VAR_3}'s\n"
	.string "already asleep!$"
#endif

@ Göre Doris (TRAINER_LASS_ALI), MAP_ROUTE24
MatchCall_Kanto_Ali_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Doris.\p"
	.string "Ich war zwar nur Nr. 2, aber eigentlich\n"
	.string "die Beste, oder?\p"
	.string "Komm zu Route 24 und beweis mir das\n"
	.string "Gegenteil!$"
#else
	.string "Hi, {PLAYER}! It's ALI.\p"
	.string "I was only No. 2, but I was really the\n"
	.string "best, right?\p"
	.string "Come to ROUTE 24 and prove me wrong!$"
#endif

MatchCall_Kanto_Ali_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Doris.\p"
	.string "Die anderen auf der Brücke sagen, ich\n"
	.string "sei die Schwächste.\p"
	.string "Pah! Mein {STR_VAR_3} sieht das ganz\n"
	.string "anders!$"
#else
	.string "Hi, {PLAYER}! It's ALI.\p"
	.string "The others on the bridge say I'm the\n"
	.string "weakest.\p"
	.string "Hmph! My {STR_VAR_3} doesn't think\n"
	.string "so!$"
#endif

@ Teenager Jannik (TRAINER_YOUNGSTER_CHAD), MAP_ROUTE25
MatchCall_Kanto_Chad_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Jannik.\p"
	.string "Ich hab wieder dieses Gefühl… Wir\n"
	.string "müssen erneut kämpfen!\p"
	.string "Ich warte auf Route 25!$"
#else
	.string "Hey, {PLAYER}! It's CHAD.\p"
	.string "I've got that feeling again… We have to\n"
	.string "battle again!\p"
	.string "I'm waiting on ROUTE 25!$"
#endif

MatchCall_Kanto_Chad_General::
#if GERMAN
	.string "Yo, {PLAYER}! Hier ist Jannik.\p"
	.string "Mein {STR_VAR_3} war verwirrt. Ich hab\n"
	.string "es sofort ausgewechselt.\p"
	.string "Genau wie ich's dir gesagt hab! Gute\n"
	.string "Taktik, oder?$"
#else
	.string "Yo, {PLAYER}! It's CHAD.\p"
	.string "My {STR_VAR_3} got confused, so I\n"
	.string "switched it out right away.\p"
	.string "Just like I told you! Good tactic, huh?$"
#endif

@ Picknicker Ruth (TRAINER_PICNICKER_KELSEY), MAP_ROUTE25
MatchCall_Kanto_Kelsey_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Ruth!\p"
	.string "Ich fühle mich heute richtig gut!\n"
	.string "Endlich bin ich in Form!\p"
	.string "Komm zu Route 25, dann kämpfen wir!$"
#else
	.string "Hi, {PLAYER}! It's KELSEY!\p"
	.string "I'm feeling really good today! My\n"
	.string "conditioning's finally back!\p"
	.string "Come to ROUTE 25 and let's battle!$"
#endif

MatchCall_Kanto_Kelsey_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Ruth.\p"
	.string "Mein Freund hat gegen mein\n"
	.string "{STR_VAR_3} verloren! Hihi!\p"
	.string "Aber er ist trotzdem cool!$"
#else
	.string "Hi, {PLAYER}! It's KELSEY.\p"
	.string "My boyfriend lost to my {STR_VAR_3}!\n"
	.string "Tee-hee!\p"
	.string "He's still cool, though!$"
#endif

@ Wanderer Kasper (TRAINER_HIKER_FRANKLIN), MAP_ROUTE25
MatchCall_Kanto_Franklin_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Kasper!\p"
	.string "Ich hab auf dem Mondberg trainiert und\n"
	.string "noch Benzin im Tank!\p"
	.string "Komm zu Route 25 für einen Kampf!$"
#else
	.string "Hey, {PLAYER}! It's FRANKLIN!\p"
	.string "I trained up on MT. MOON, and I've still\n"
	.string "got gas in the tank!\p"
	.string "Come to ROUTE 25 for a battle!$"
#endif

MatchCall_Kanto_Franklin_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Kasper.\p"
	.string "Im Mondberg wollte mich wieder ein\n"
	.string "Zubat beißen!\p"
	.string "Aber mein {STR_VAR_3} hat es\n"
	.string "verscheucht. Wahahaha!$"
#else
	.string "Hey, {PLAYER}! It's FRANKLIN.\p"
	.string "A ZUBAT tried to bite me again in\n"
	.string "MT. MOON!\p"
	.string "But my {STR_VAR_3} chased it off.\n"
	.string "Wahahaha!$"
#endif

@ Wanderer Minoru (TRAINER_HIKER_NOB), MAP_ROUTE25
MatchCall_Kanto_Nob_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Minoru!\p"
	.string "Ich bin wieder auf dem Weg zum Kap. Aber\n"
	.string "vorher will ich kämpfen!\p"
	.string "Komm zu Route 25!$"
#else
	.string "Hey, {PLAYER}! It's NOB!\p"
	.string "I'm on my way to the cape again. But\n"
	.string "first I want a battle!\p"
	.string "Come to ROUTE 25!$"
#endif

MatchCall_Kanto_Nob_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Minoru.\p"
	.string "Am Kap hab ich so viele seltene Pokémon\n"
	.string "gesehen!\p"
	.string "Mein {STR_VAR_3} wirkt dagegen ganz\n"
	.string "normal. Wahahaha!$"
#else
	.string "Hey, {PLAYER}! It's NOB.\p"
	.string "I saw so many rare POKéMON at the cape!\p"
	.string "My {STR_VAR_3} looks plain next to\n"
	.string "them. Wahahaha!$"
#endif

@ Camper Günther (TRAINER_CAMPER_RICKY), MAP_ROUTE6
MatchCall_Kanto_Ricky_Battle::
#if GERMAN
	.string "Psst, {PLAYER}! Hier ist Günther.\p"
	.string "Du bist doch dieses neugierige Kind…\n"
	.string "Belauschst du uns etwa wieder?\p"
	.string "Komm zu Route 6, dann klären wir das!$"
#else
	.string "Psst, {PLAYER}! It's RICKY.\p"
	.string "You're that nosy kid… Are you\n"
	.string "eavesdropping again?\p"
	.string "Come to ROUTE 6 and we'll settle this!$"
#endif

MatchCall_Kanto_Ricky_General::
#if GERMAN
	.string "Psst, {PLAYER}! Hier ist Günther.\p"
	.string "Ein Geheimnis: Mein {STR_VAR_3} kann\n"
	.string "eine neue Attacke!\p"
	.string "Flüster… Tuschel… Mehr sag ich nicht!$"
#else
	.string "Psst, {PLAYER}! It's RICKY.\p"
	.string "Here's a secret: my {STR_VAR_3}\n"
	.string "learned a new move!\p"
	.string "Whisper… Whisper… That's all I'm saying!$"
#endif

@ Camper Raphael (TRAINER_CAMPER_JEFF), MAP_ROUTE6
MatchCall_Kanto_Jeff_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Raphael.\p"
	.string "Ich hab jetzt mehr Pokémon dabei und\n"
	.string "fühl mich sicher!\p"
	.string "Komm zu Route 6 für einen Kampf!$"
#else
	.string "Hey, {PLAYER}! It's JEFF.\p"
	.string "I've got more POKéMON with me now, so I\n"
	.string "feel safer!\p"
	.string "Come to ROUTE 6 for a battle!$"
#endif

MatchCall_Kanto_Jeff_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Raphael.\p"
	.string "Mit {STR_VAR_3} an meiner Seite hab\n"
	.string "ich keine Angst mehr.\p"
	.string "Na ja, im Dunkeln vielleicht ein\n"
	.string "bisschen…$"
#else
	.string "Hey, {PLAYER}! It's JEFF.\p"
	.string "With {STR_VAR_3} at my side, I'm not\n"
	.string "scared anymore.\p"
	.string "Well, maybe a little in the dark…$"
#endif

@ Picknicker Hedwig (TRAINER_PICNICKER_ISABELLE), MAP_ROUTE6
MatchCall_Kanto_Isabelle_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Hedwig.\p"
	.string "Ich kenne jetzt dein Geheimnis! Ich bin\n"
	.string "viel stärker geworden!\p"
	.string "Komm zu Route 6, dann zeig ich's dir!$"
#else
	.string "Hi, {PLAYER}! It's ISABELLE.\p"
	.string "I think I know your secret now! I've\n"
	.string "gotten much stronger!\p"
	.string "Come to ROUTE 6 and I'll show you!$"
#endif

MatchCall_Kanto_Isabelle_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Hedwig.\p"
	.string "Ich trainiere jeden Tag mit\n"
	.string "{STR_VAR_3}.\p"
	.string "Ist das dein Geheimnis? Einfach jeden\n"
	.string "Tag trainieren?$"
#else
	.string "Hi, {PLAYER}! It's ISABELLE.\p"
	.string "I train with {STR_VAR_3} every day.\p"
	.string "Is that your secret? Just training\n"
	.string "every day?$"
#endif

@ Teenager Valentin (TRAINER_YOUNGSTER_YASU), MAP_ROUTE11
MatchCall_Kanto_Yasu_Battle::
#if GERMAN
	.string "Yo, {PLAYER}! Hier ist Valentin!\p"
	.string "Ich trainiere Tag und Nacht. In meiner\n"
	.string "Klasse bin ich immer noch der Beste!\p"
	.string "Komm zu Route 11!$"
#else
	.string "Yo, {PLAYER}! It's YASU!\p"
	.string "I train morning and night. I'm still the\n"
	.string "best in my class!\p"
	.string "Come to ROUTE 11!$"
#endif

MatchCall_Kanto_Yasu_General::
#if GERMAN
	.string "Yo, {PLAYER}! Hier ist Valentin.\p"
	.string "Ich war heute um fünf auf und hab mit\n"
	.string "{STR_VAR_3} trainiert.\p"
	.string "Deshalb bin ich der Beste!$"
#else
	.string "Yo, {PLAYER}! It's YASU.\p"
	.string "I got up at five today to train with\n"
	.string "{STR_VAR_3}.\p"
	.string "That's why I'm the best!$"
#endif

@ Mechaniker Hasso (TRAINER_ENGINEER_BERNIE), MAP_ROUTE11
MatchCall_Kanto_Bernie_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}. Hier ist Hasso.\p"
	.string "Ich hab Feierabend! Meine Pokémon\n"
	.string "stehen unter Hochspannung!\p"
	.string "Komm zu Route 11 für einen Kampf!$"
#else
	.string "Hello, {PLAYER}. It's BERNIE.\p"
	.string "My shift's over! My POKéMON are fully\n"
	.string "charged!\p"
	.string "Come to ROUTE 11 for a battle!$"
#endif

MatchCall_Kanto_Bernie_General::
#if GERMAN
	.string "Hallo, {PLAYER}. Hier ist Hasso.\p"
	.string "Mein {STR_VAR_3} hat mir heute bei der\n"
	.string "Arbeit geholfen.\p"
	.string "Dafür bekommt es heute Abend eine\n"
	.string "Extraportion!$"
#else
	.string "Hello, {PLAYER}. It's BERNIE.\p"
	.string "My {STR_VAR_3} helped me at work\n"
	.string "today.\p"
	.string "It gets an extra helping tonight!$"
#endif

@ Spieler Marco (TRAINER_GAMER_DARIAN), MAP_ROUTE11
MatchCall_Kanto_Darian_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}… Hier ist Marco.\p"
	.string "Ich habe noch nie gewonnen… Aber heute\n"
	.string "hab ich ein gutes Gefühl!\p"
	.string "Komm zu Route 11. Vielleicht ist heute\n"
	.string "mein Tag…$"
#else
	.string "Hello, {PLAYER}… It's DARIAN.\p"
	.string "I've never won before… But I've got a\n"
	.string "good feeling today!\p"
	.string "Come to ROUTE 11. Maybe today's my day…$"
#endif

MatchCall_Kanto_Darian_General::
#if GERMAN
	.string "Hallo, {PLAYER}… Hier ist Marco.\p"
	.string "Ich hab heute ein vierblättriges\n"
	.string "Kleeblatt gefunden!\p"
	.string "Aber {STR_VAR_3} hat es gefressen…\n"
	.string "Typisch.$"
#else
	.string "Hello, {PLAYER}… It's DARIAN.\p"
	.string "I found a four-leaf clover today!\p"
	.string "But {STR_VAR_3} ate it… Typical.$"
#endif

@ Camper Chris (TRAINER_CAMPER_CHRIS), MAP_ROUTE9
MatchCall_Kanto_Chris_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Chris.\p"
	.string "Ich hab deine bezaubernden Pokémon\n"
	.string "nicht vergessen!\p"
	.string "Komm zu Route 9, dann sehen wir, wer das\n"
	.string "bessere Team hat!$"
#else
	.string "Hey, {PLAYER}! It's CHRIS.\p"
	.string "I haven't forgotten your good-looking\n"
	.string "POKéMON!\p"
	.string "Come to ROUTE 9 and we'll see whose\n"
	.string "team is better!$"
#endif

MatchCall_Kanto_Chris_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Chris.\p"
	.string "Alle sagen, dass mein {STR_VAR_3}\n"
	.string "richtig fit aussieht.\p"
	.string "Deine Pokémon haben mich angespornt!$"
#else
	.string "Hey, {PLAYER}! It's CHRIS.\p"
	.string "Everyone says my {STR_VAR_3} looks\n"
	.string "really fit.\p"
	.string "Your POKéMON inspired me!$"
#endif

@ Picknicker Ingeborg (TRAINER_PICNICKER_ALICIA), MAP_ROUTE9
MatchCall_Kanto_Alicia_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Ingeborg.\p"
	.string "Dieses Mal bist du dran! Ich hab richtig\n"
	.string "hart trainiert!\p"
	.string "Komm zu Route 9!$"
#else
	.string "Hi, {PLAYER}! It's ALICIA.\p"
	.string "This time, you're mine! I've trained\n"
	.string "really hard!\p"
	.string "Come to ROUTE 9!$"
#endif

MatchCall_Kanto_Alicia_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Ingeborg.\p"
	.string "Ich war im Felstunnel. Ohne Blitz hab\n"
	.string "ich gar nichts gesehen!\p"
	.string "Zum Glück hat mich {STR_VAR_3}\n"
	.string "rausgeführt.$"
#else
	.string "Hi, {PLAYER}! It's ALICIA.\p"
	.string "I went into ROCK TUNNEL. I couldn't see\n"
	.string "a thing without FLASH!\p"
	.string "Luckily, {STR_VAR_3} led me out.$"
#endif

@ Wanderer Jens (TRAINER_HIKER_JEREMY), MAP_ROUTE9
MatchCall_Kanto_Jeremy_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Jens!\p"
	.string "Mir ist schon wieder richtig langweilig!\p"
	.string "Komm zu Route 9, dann haben wir Spaß!\n"
	.string "Wahahaha!$"
#else
	.string "Bwahaha! {PLAYER}! It's JEREMY!\p"
	.string "I'm bored again, eh!\p"
	.string "Come to ROUTE 9 and let's have some\n"
	.string "fun!$"
#endif

MatchCall_Kanto_Jeremy_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Jens.\p"
	.string "Ich sitze vor dem Felstunnel und warte\n"
	.string "auf Gegner.\p"
	.string "{STR_VAR_3} ist schon eingeschlafen.\n"
	.string "Wahahaha!$"
#else
	.string "Hey, {PLAYER}! It's JEREMY.\p"
	.string "I'm sitting by ROCK TUNNEL waiting for\n"
	.string "opponents.\p"
	.string "{STR_VAR_3} already fell asleep.\n"
	.string "Bwahaha!$"
#endif

@ Pokémaniac Mark (TRAINER_POKEMANIAC_MARK), MAP_ROUTE10
MatchCall_Kanto_Mark_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Mark.\p"
	.string "Meine Sammlung ist gewachsen! Möchtest\n"
	.string "du sie sehen?\p"
	.string "Komm zu Route 10!$"
#else
	.string "Hi, {PLAYER}! It's MARK.\p"
	.string "My collection has grown! Want to see it?\p"
	.string "Come to ROUTE 10!$"
#endif

MatchCall_Kanto_Mark_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Mark.\p"
	.string "Mein {STR_VAR_3} ist das Prunkstück\n"
	.string "meiner Sammlung.\p"
	.string "Zu Hause hat es ein eigenes Zimmer!$"
#else
	.string "Hi, {PLAYER}! It's MARK.\p"
	.string "My {STR_VAR_3} is the jewel of my\n"
	.string "collection.\p"
	.string "It has its own room at home!$"
#endif

@ Pokémaniac Benno (TRAINER_POKEMANIAC_HERMAN), MAP_ROUTE10
MatchCall_Kanto_Herman_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Benno.\p"
	.string "Hab ich dir schon meine Pokémon\n"
	.string "gezeigt? Sie sind jetzt viel stärker!\p"
	.string "Komm zu Route 10!$"
#else
	.string "Hi, {PLAYER}! It's HERMAN.\p"
	.string "Did I show you my POKéMON? They're much\n"
	.string "stronger now!\p"
	.string "Come to ROUTE 10!$"
#endif

MatchCall_Kanto_Herman_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Benno.\p"
	.string "Ich kann dich immer noch nicht leiden!\p"
	.string "Aber mein {STR_VAR_3} fragt dauernd\n"
	.string "nach dir. Also ruf ich an.$"
#else
	.string "Hi, {PLAYER}! It's HERMAN.\p"
	.string "I still don't like you!\p"
	.string "But my {STR_VAR_3} keeps asking\n"
	.string "about you. So I'm calling.$"
#endif

@ Wanderer Heimke (TRAINER_HIKER_TRENT), MAP_ROUTE10
MatchCall_Kanto_Trent_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Heimke!\p"
	.string "Ahh! Die Bergluft ist wieder wunderbar\n"
	.string "erfrischend!\p"
	.string "Komm zu Route 10, ich will kämpfen!$"
#else
	.string "Hey, {PLAYER}! It's TRENT!\p"
	.string "Ah! The mountain air is delicious again!\p"
	.string "Come to ROUTE 10, I want to battle!$"
#endif

MatchCall_Kanto_Trent_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Heimke.\p"
	.string "Ich hab ganz tief eingeatmet. Jetzt ist\n"
	.string "mir schwindelig!\p"
	.string "{STR_VAR_3} lacht mich aus…$"
#else
	.string "Hey, {PLAYER}! It's TRENT.\p"
	.string "I took a really deep breath. Now I'm\n"
	.string "dizzy!\p"
	.string "{STR_VAR_3} is laughing at me…$"
#endif

@ Göre Leila (TRAINER_LASS_MEGAN), MAP_ROUTE8
MatchCall_Kanto_Megan_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Leila.\p"
	.string "Ich stehe immer noch hier herum… Aber\n"
	.string "kämpfen kann ich!\p"
	.string "Komm zu Route 8!$"
#else
	.string "Hi, {PLAYER}! It's MEGAN.\p"
	.string "I'm still standing around here… But I\n"
	.string "can battle!\p"
	.string "Come to ROUTE 8!$"
#endif

MatchCall_Kanto_Megan_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Leila.\p"
	.string "Der Wachtposten hat meinem\n"
	.string "{STR_VAR_3} heute zugewinkt!\p"
	.string "Vielleicht ist er doch nicht so gemein.$"
#else
	.string "Hi, {PLAYER}! It's MEGAN.\p"
	.string "The gatekeeper waved at my\n"
	.string "{STR_VAR_3} today!\p"
	.string "Maybe he's not so mean after all.$"
#endif

@ Streber Gerrit (TRAINER_SUPER_NERD_GLENN), MAP_ROUTE8
MatchCall_Kanto_Glenn_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}. Hier ist Gerrit.\p"
	.string "Meine neue Strategie ist fertig!\n"
	.string "Befolgst du meinen Rat?\p"
	.string "Komm zu Route 8, dann teste ich sie an\n"
	.string "dir!$"
#else
	.string "Hello, {PLAYER}. It's GLENN.\p"
	.string "My new strategy is ready! Are you\n"
	.string "following my advice?\p"
	.string "Come to ROUTE 8 and I'll test it on you!$"
#endif

MatchCall_Kanto_Glenn_General::
#if GERMAN
	.string "Hallo, {PLAYER}. Hier ist Gerrit.\p"
	.string "Erst {STR_VAR_3}… und… und… dann…\n"
	.string "Hm.\p"
	.string "Ich habe den Faden verloren. Ich ruf\n"
	.string "später noch mal an.$"
#else
	.string "Hello, {PLAYER}. It's GLENN.\p"
	.string "First {STR_VAR_3}… and… and… then…\n"
	.string "Hmm.\p"
	.string "I lost my train of thought. I'll call\n"
	.string "back later.$"
#endif

@ Spieler Rick (TRAINER_GAMER_RICH), MAP_ROUTE8
MatchCall_Kanto_Rich_Battle::
#if GERMAN
	.string "Yo, {PLAYER}! Hier ist Rick!\p"
	.string "Ich hab eine Glückssträhne! Heute\n"
	.string "knack ich den Jackpot!\p"
	.string "Komm zu Route 8, wir spielen eine Runde!$"
#else
	.string "Yo, {PLAYER}! It's RICH!\p"
	.string "I'm on a winning streak! Today I'm\n"
	.string "hitting the jackpot!\p"
	.string "Come to ROUTE 8 for a round!$"
#endif

MatchCall_Kanto_Rich_General::
#if GERMAN
	.string "Yo, {PLAYER}! Hier ist Rick.\p"
	.string "In der Spielhalle in Prismania City hab\n"
	.string "ich alle Münzen verspielt…\p"
	.string "Aber mein {STR_VAR_3} bringt mir\n"
	.string "bestimmt bald wieder Glück!$"
#else
	.string "Yo, {PLAYER}! It's RICH.\p"
	.string "I lost all my coins at the GAME CORNER\n"
	.string "in CELADON…\p"
	.string "But my {STR_VAR_3} is sure to bring me\n"
	.string "luck again soon!$"
#endif

@ Zwillinge Nora&Jo (TRAINER_TWINS_ELI_ANNE), MAP_ROUTE8
MatchCall_Kanto_EliAnne_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier sind Nora und Jo!\p"
	.string "Unsere Zwillings-Kraft ist noch stärker\n"
	.string "geworden!\p"
	.string "Komm zu Route 8, dann zeigen wir sie dir!$"
#else
	.string "Hi, {PLAYER}! It's the twins!\p"
	.string "Our twin power got even stronger!\p"
	.string "Come to ROUTE 8 and we'll show you!$"
#endif

MatchCall_Kanto_EliAnne_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier sind Nora und Jo.\p"
	.string "Wir haben beide gleichzeitig geniest!\n"
	.string "Und {STR_VAR_3} auch!\p"
	.string "Zwillinge eben!$"
#else
	.string "Hi, {PLAYER}! It's the twins.\p"
	.string "We both sneezed at the same time! And\n"
	.string "{STR_VAR_3} did too!\p"
	.string "That's twins for you!$"
#endif

@ Biker Kamillo (TRAINER_BIKER_JAREN), MAP_ROUTE8
MatchCall_Kanto_Jaren_Battle::
#if GERMAN
	.string "Hey, Kiddie! Hier ist Kamillo.\p"
	.string "Dieses Mal bin ich nicht so gnädig!\p"
	.string "Komm zu Route 8, wenn du dich traust!$"
#else
	.string "Hey, kid! It's JAREN.\p"
	.string "Don't expect mercy this time!\p"
	.string "Come to ROUTE 8 if you dare!$"
#endif

MatchCall_Kanto_Jaren_General::
#if GERMAN
	.string "Hey, Kiddie! Hier ist Kamillo.\p"
	.string "Mein {STR_VAR_3} hat heute einen\n"
	.string "Radfahrer erschreckt.\p"
	.string "Der ist glatt umgekippt! Hahaha!$"
#else
	.string "Hey, kid! It's JAREN.\p"
	.string "My {STR_VAR_3} scared a cyclist\n"
	.string "today.\p"
	.string "He fell right over! Hahaha!$"
#endif

@ Angler Alois (TRAINER_FISHERMAN_ELLIOT), MAP_ROUTE12
MatchCall_Kanto_Elliot_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}. Hier ist Alois.\p"
	.string "Arbeit hab ich immer noch keine… Aber\n"
	.string "Zeit zum Angeln!\p"
	.string "Mein Team ist bereit. Komm doch zu\n"
	.string "Route 12!$"
#else
	.string "Hello, {PLAYER}. It's ELLIOT.\p"
	.string "Still no work for me… But plenty of time\n"
	.string "to fish!\p"
	.string "My team's ready. Why not come to\n"
	.string "ROUTE 12?$"
#endif

MatchCall_Kanto_Elliot_General::
#if GERMAN
	.string "Hallo, {PLAYER}. Hier ist Alois.\p"
	.string "Heute hab ich ein {STR_VAR_3}\n"
	.string "geangelt. Wieder keine Arbeit…\p"
	.string "Aber das Angeln aufzugeben ist einfach\n"
	.string "zu schwer!$"
#else
	.string "Hello, {PLAYER}. It's ELLIOT.\p"
	.string "I hooked a {STR_VAR_3} today. Still no\n"
	.string "work, though…\p"
	.string "But it's just too hard to give up\n"
	.string "fishing!$"
#endif

@ Rocker Xaver (TRAINER_ROCKER_LUCA), MAP_ROUTE12
MatchCall_Kanto_Luca_Battle::
#if GERMAN
	.string "Yo, {PLAYER}! Hier ist Xaver!\p"
	.string "Meine Pokémon stehen unter Strom!\n"
	.string "Elektrizität ist meine Stärke!\p"
	.string "Komm zu Route 12!$"
#else
	.string "Yo, {PLAYER}! It's LUCA!\p"
	.string "My POKéMON are fully charged!\n"
	.string "Electricity's my specialty!\p"
	.string "Come to ROUTE 12!$"
#endif

MatchCall_Kanto_Luca_General::
#if GERMAN
	.string "Yo, {PLAYER}! Hier ist Xaver.\p"
	.string "Ich war mit {STR_VAR_3} angeln. Ein\n"
	.string "Wasser-Pokémon hat angebissen!\p"
	.string "Ich hab immer noch keine Ahnung von\n"
	.string "denen…$"
#else
	.string "Yo, {PLAYER}! It's LUCA.\p"
	.string "I went fishing with {STR_VAR_3}. A sea\n"
	.string "POKéMON bit!\p"
	.string "I still don't know a thing about them…$"
#endif

@ Junges Glück Sira&Deniz (TRAINER_YOUNG_COUPLE_GIA_JES), MAP_ROUTE12
MatchCall_Kanto_GiaJes_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier sind Sira und Deniz!\p"
	.string "Wenn wir heute gewinnen, heiraten wir!\p"
	.string "Komm zu Route 12!$"
#else
	.string "Hi, {PLAYER}! It's the young couple!\p"
	.string "If we win today, we're getting married!\p"
	.string "Come to ROUTE 12!$"
#endif

MatchCall_Kanto_GiaJes_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Deniz.\p"
	.string "Ich hab Sira einen Ring gekauft! Aber\n"
	.string "{STR_VAR_3} hat ihn versteckt…\p"
	.string "Psst! Sag ihr nichts!$"
#else
	.string "Hi, {PLAYER}! It's the groom-to-be.\p"
	.string "I bought a ring! But {STR_VAR_3} hid\n"
	.string "it…\p"
	.string "Shh! Don't tell her!$"
#endif

@ Schönheit Sylvia (TRAINER_BEAUTY_SHEILA), MAP_ROUTE13
MatchCall_Kanto_Sheila_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Sylvia.\p"
	.string "Hast du unseren Kampf schon\n"
	.string "vergessen? Ich nicht!\p"
	.string "Komm zu Route 13!$"
#else
	.string "Hello, {PLAYER}! It's SHEILA.\p"
	.string "Have you forgotten our battle yet? I\n"
	.string "haven't!\p"
	.string "Come to ROUTE 13!$"
#endif

MatchCall_Kanto_Sheila_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Sylvia.\p"
	.string "Ich weiß jetzt, welche Attacken\n"
	.string "{STR_VAR_3} kann!\p"
	.string "Ich kenne mich also schon besser mit\n"
	.string "Pokémon aus. Ein bisschen…$"
#else
	.string "Hello, {PLAYER}! It's SHEILA.\p"
	.string "I learned which moves {STR_VAR_3}\n"
	.string "knows!\p"
	.string "So I know more about POKéMON now. A\n"
	.string "little…$"
#endif

@ Vogelfänger Fritjof (TRAINER_BIRD_KEEPER_ROBERT), MAP_ROUTE13
MatchCall_Kanto_Robert_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Fritjof.\p"
	.string "Meine Vogel-Pokémon sind bereit! Sie\n"
	.string "begleiten mich überallhin!\p"
	.string "Komm zu Route 13!$"
#else
	.string "Hi, {PLAYER}! It's ROBERT.\p"
	.string "My bird POKéMON are ready! They go\n"
	.string "everywhere with me!\p"
	.string "Come to ROUTE 13!$"
#endif

MatchCall_Kanto_Robert_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Fritjof.\p"
	.string "Ich hab heute mit {STR_VAR_3}\n"
	.string "Flügelschlagen geübt.\p"
	.string "Fliegen kann ich immer noch nicht… Aber\n"
	.string "ich gebe nicht auf!$"
#else
	.string "Hi, {PLAYER}! It's ROBERT.\p"
	.string "I practiced flapping my arms with\n"
	.string "{STR_VAR_3} today.\p"
	.string "I still can't fly… But I won't give up!$"
#endif

@ Picknicker Janka (TRAINER_PICNICKER_SUSIE), MAP_ROUTE13
MatchCall_Kanto_Susie_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Janka!\p"
	.string "Ich hab fleißig geübt! Ich will die\n"
	.string "beste Trainerin sein!\p"
	.string "Komm zu Route 13!$"
#else
	.string "Hi, {PLAYER}! It's SUSIE!\p"
	.string "I've been training hard! I want to be\n"
	.string "the best TRAINER!\p"
	.string "Come to ROUTE 13!$"
#endif

MatchCall_Kanto_Susie_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Janka.\p"
	.string "Mein {STR_VAR_3} und ich üben jeden\n"
	.string "Tag nach der Schule.\p"
	.string "Bald bin ich eine richtig gute Trainerin!$"
#else
	.string "Hi, {PLAYER}! It's SUSIE.\p"
	.string "My {STR_VAR_3} and I practice every\n"
	.string "day after school.\p"
	.string "Soon I'll be a really good TRAINER!$"
#endif

@ Biker Darius (TRAINER_BIKER_LUKAS), MAP_ROUTE14
MatchCall_Kanto_Lukas_Battle::
#if GERMAN
	.string "Los, los, {PLAYER}! Hier ist Darius!\p"
	.string "Lass uns kämpfen! Auf in den Kampf!\n"
	.string "Los!\p"
	.string "Komm zu Route 14!$"
#else
	.string "C'mon, c'mon, {PLAYER}! It's LUKAS!\p"
	.string "Let's go, let's go, let's go!\p"
	.string "Come to ROUTE 14!$"
#endif

MatchCall_Kanto_Lukas_General::
#if GERMAN
	.string "Was, was, was? Ach, {PLAYER}! Hier ist\n"
	.string "Darius.\p"
	.string "Mein {STR_VAR_3} ist heute so\n"
	.string "schnell! Los, los, los!\p"
	.string "Ich kann einfach nicht stillsitzen!$"
#else
	.string "What, what, what? Oh, {PLAYER}! It's\n"
	.string "LUKAS.\p"
	.string "My {STR_VAR_3}'s so fast today! Go,\n"
	.string "go, go!\p"
	.string "I just can't sit still!$"
#endif

@ Vogelfänger Genadi (TRAINER_BIRD_KEEPER_BENNY), MAP_ROUTE14
MatchCall_Kanto_Benny_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}. Hier ist Genadi.\p"
	.string "Ich will nicht unbedingt… Aber lass uns\n"
	.string "dennoch kämpfen!\p"
	.string "Komm zu Route 14.$"
#else
	.string "Hi, {PLAYER}. It's BENNY.\p"
	.string "I'm not really into it… But okay, let's\n"
	.string "battle!\p"
	.string "Come to ROUTE 14.$"
#endif

MatchCall_Kanto_Benny_General::
#if GERMAN
	.string "Hallo, {PLAYER}. Hier ist Genadi.\p"
	.string "Ich liege im Gras und schaue mit\n"
	.string "{STR_VAR_3} in den Himmel.\p"
	.string "Unter diesem riesigen Himmel ist alles\n"
	.string "so unwichtig…$"
#else
	.string "Hi, {PLAYER}. It's BENNY.\p"
	.string "I'm lying in the grass, looking at the\n"
	.string "sky with {STR_VAR_3}.\p"
	.string "Everything's so insignificant under\n"
	.string "this huge sky…$"
#endif

@ Vogelfänger Armin (TRAINER_BIRD_KEEPER_CARTER), MAP_ROUTE14
MatchCall_Kanto_Carter_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Armin.\p"
	.string "Ich hab meinen Pokémon mit TMs gute\n"
	.string "Attacken beigebracht!\p"
	.string "Komm zu Route 14 und sieh selbst!$"
#else
	.string "Hi, {PLAYER}! It's CARTER.\p"
	.string "I used TMs to teach my POKéMON good\n"
	.string "moves!\p"
	.string "Come to ROUTE 14 and see for yourself!$"
#endif

MatchCall_Kanto_Carter_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Armin.\p"
	.string "Welche TM soll ich {STR_VAR_3} als\n"
	.string "Nächstes beibringen?\p"
	.string "Ich kann mich einfach nicht\n"
	.string "entscheiden!$"
#else
	.string "Hi, {PLAYER}! It's CARTER.\p"
	.string "Which TM should I teach {STR_VAR_3}\n"
	.string "next?\p"
	.string "I just can't decide!$"
#endif

@ Vogelfänger Anton (TRAINER_BIRD_KEEPER_MARLON), MAP_ROUTE14
MatchCall_Kanto_Marlon_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Anton.\p"
	.string "Hast du deinem Vogel-Pokémon schon\n"
	.string "das Fliegen beigebracht?\p"
	.string "Dann flieg zu Route 14!$"
#else
	.string "Hi, {PLAYER}! It's MARLON.\p"
	.string "Have you taught your bird POKéMON how\n"
	.string "to FLY?\p"
	.string "Then fly over to ROUTE 14!$"
#endif

MatchCall_Kanto_Marlon_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Anton.\p"
	.string "Ich hab {STR_VAR_3} heute\n"
	.string "stundenlang beim Training zugeschaut.\p"
	.string "Ich will nichts anderes als\n"
	.string "Vogel-Pokémon trainieren!$"
#else
	.string "Hi, {PLAYER}! It's MARLON.\p"
	.string "I watched {STR_VAR_3} train for hours\n"
	.string "today.\p"
	.string "I don't want to raise anything but bird\n"
	.string "POKéMON!$"
#endif

@ Schönheit Ilona (TRAINER_BEAUTY_GRACE), MAP_ROUTE15
MatchCall_Kanto_Grace_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Ilona.\p"
	.string "Du bist so niedlich! Wie ein kleines,\n"
	.string "süßes Pokémon!\p"
	.string "Komm zu Route 15, ich will gegen dich\n"
	.string "kämpfen!$"
#else
	.string "Hello, {PLAYER}! It's GRACE.\p"
	.string "You're such a cutie! So like a darling\n"
	.string "POKéMON!\p"
	.string "Come to ROUTE 15, I want to battle you!$"
#endif

MatchCall_Kanto_Grace_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Ilona.\p"
	.string "Ich hab {STR_VAR_3} eine Schleife\n"
	.string "umgebunden.\p"
	.string "Jetzt ist es fast so niedlich wie du!$"
#else
	.string "Hello, {PLAYER}! It's GRACE.\p"
	.string "I tied a ribbon on {STR_VAR_3}.\p"
	.string "Now it's almost as cute as you!$"
#endif

@ Vogelfänger Vitali (TRAINER_BIRD_KEEPER_CHESTER), MAP_ROUTE15
MatchCall_Kanto_Chester_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Vitali.\p"
	.string "Meine Vögel erschaudern schon, wenn sie\n"
	.string "an dich denken!\p"
	.string "Komm zu Route 15!$"
#else
	.string "Hi, {PLAYER}! It's CHESTER.\p"
	.string "My birds shiver just thinking about\n"
	.string "you!\p"
	.string "Come to ROUTE 15!$"
#endif

MatchCall_Kanto_Chester_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Vitali.\p"
	.string "Ein Gegner hat Erdbeben gegen\n"
	.string "{STR_VAR_3} eingesetzt.\p"
	.string "Keine Wirkung! Hahaha! Das weiß doch\n"
	.string "jeder!$"
#else
	.string "Hi, {PLAYER}! It's CHESTER.\p"
	.string "An opponent used EARTHQUAKE on\n"
	.string "{STR_VAR_3}.\p"
	.string "No effect! Hahaha! Everyone knows\n"
	.string "that!$"
#endif

@ Picknicker Heidi (TRAINER_PICNICKER_BECKY), MAP_ROUTE15
MatchCall_Kanto_Becky_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Heidi.\p"
	.string "Du siehst immer noch lammfromm aus!\n"
	.string "Einen Versuch hab ich noch!\p"
	.string "Komm zu Route 15!$"
#else
	.string "Hi, {PLAYER}! It's BECKY.\p"
	.string "You still look gentle! I'll give it one\n"
	.string "more go!\p"
	.string "Come to ROUTE 15!$"
#endif

MatchCall_Kanto_Becky_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Heidi.\p"
	.string "Heute ist ein Biker an mir\n"
	.string "vorbeigefahren!\p"
	.string "Zum Glück hat ihn {STR_VAR_3}\n"
	.string "verscheucht. Weg war er!$"
#else
	.string "Hi, {PLAYER}! It's BECKY.\p"
	.string "A BIKER rode right past me today!\p"
	.string "Luckily, {STR_VAR_3} scared him off.\n"
	.string "He was gone in a flash!$"
#endif

@ Mühlensippe Sergio&Eva (TRAINER_CRUSH_KIN_RON_MYA), MAP_ROUTE15
MatchCall_Kanto_RonMya_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Eva.\p"
	.string "Mein kleiner Bruder braucht wieder\n"
	.string "Training. Hilfst du mir?\p"
	.string "Komm zu Route 15!$"
#else
	.string "Hi, {PLAYER}! It's the big sister.\p"
	.string "My little brother needs more training.\n"
	.string "Will you help?\p"
	.string "Come to ROUTE 15!$"
#endif

MatchCall_Kanto_RonMya_General::
#if GERMAN
	.string "Hallo, {PLAYER}… Hier ist Sergio.\p"
	.string "Meine Schwester ist noch strenger. Und\n"
	.string "{STR_VAR_3} hilft ihr auch noch!\p"
	.string "Rette mich!$"
#else
	.string "Hi, {PLAYER}… It's the little brother.\p"
	.string "My sister got even stricter. And\n"
	.string "{STR_VAR_3} is helping her!\p"
	.string "Save me!$"
#endif

@ Biker Trutz (TRAINER_BIKER_RUBEN), MAP_ROUTE16
MatchCall_Kanto_Ruben_Battle::
#if GERMAN
	.string "Heh, {PLAYER}! Hier ist Trutz.\p"
	.string "Wir werden uns jetzt amüsieren! Meine\n"
	.string "Pokémon können es kaum erwarten!\p"
	.string "Komm zu Route 16!$"
#else
	.string "Hey, {PLAYER}! It's RUBEN.\p"
	.string "We'll have ourselves a good time! My\n"
	.string "POKéMON can't wait!\p"
	.string "Come to ROUTE 16!$"
#endif

MatchCall_Kanto_Ruben_General::
#if GERMAN
	.string "Heh, {PLAYER}! Hier ist Trutz.\p"
	.string "Mein {STR_VAR_3} hat heute einen\n"
	.string "Wanderer erschreckt!\p"
	.string "Der ist schreiend davongelaufen!\n"
	.string "Hehehe!$"
#else
	.string "Hey, {PLAYER}! It's RUBEN.\p"
	.string "My {STR_VAR_3} startled a hiker\n"
	.string "today!\p"
	.string "He ran off screaming! Hehehe!$"
#endif

@ Glatzkopf Lenny (TRAINER_CUE_BALL_CAMRON), MAP_ROUTE16
MatchCall_Kanto_Camron_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Lenny!\p"
	.string "Ich habe Hunger und bin fies! Ich\n"
	.string "brauche einen Sandsack!\p"
	.string "Komm zu Route 16!$"
#else
	.string "Hey, {PLAYER}! It's CAMRON!\p"
	.string "I'm feeling hungry and mean! I need a\n"
	.string "punching bag!\p"
	.string "Come to ROUTE 16!$"
#endif

MatchCall_Kanto_Camron_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Lenny.\p"
	.string "Mein {STR_VAR_3} wird jeden Tag\n"
	.string "wilder!\p"
	.string "Bald strotzt es noch mehr vor Kraft als\n"
	.string "ich!$"
#else
	.string "Hey, {PLAYER}! It's CAMRON.\p"
	.string "My {STR_VAR_3} gets fiercer every\n"
	.string "day!\p"
	.string "Soon it'll be even more ferocious than\n"
	.string "me!$"
#endif

@ Junges Glück Lena&Uwe (TRAINER_YOUNG_COUPLE_LEA_JED), MAP_ROUTE16
MatchCall_Kanto_LeaJed_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier sind Lena und Uwe!\p"
	.string "Willst du unsere grenzenlose Liebe\n"
	.string "sehen?\p"
	.string "Dann komm zu Route 16!$"
#else
	.string "Hi, {PLAYER}! It's the young couple!\p"
	.string "Want to see our love, which knows no\n"
	.string "bounds?\p"
	.string "Then come to ROUTE 16!$"
#endif

MatchCall_Kanto_LeaJed_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Lena.\p"
	.string "Uwe hat mir heute ein Gedicht über\n"
	.string "{STR_VAR_3} geschrieben.\p"
	.string "Ist er nicht toll?$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "My sweetheart wrote me a poem about\n"
	.string "{STR_VAR_3} today.\p"
	.string "Isn't he wonderful?$"
#endif

@ Biker Konrad (TRAINER_BIKER_JAXON), MAP_ROUTE17
MatchCall_Kanto_Jaxon_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Konrad!\p"
	.string "Fährt sich dein Fahrrad immer noch so\n"
	.string "gut?\p"
	.string "Komm zum Radweg auf Route 17!$"
#else
	.string "Hey, {PLAYER}! It's JAXON!\p"
	.string "Does your BIKE still handle so well?\p"
	.string "Come to CYCLING ROAD on ROUTE 17!$"
#endif

MatchCall_Kanto_Jaxon_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Konrad.\p"
	.string "Ich bin schon wieder vom Fahrrad\n"
	.string "gefallen. Dieses Gefälle!\p"
	.string "Zum Glück hat {STR_VAR_3} mich\n"
	.string "aufgefangen.$"
#else
	.string "Hey, {PLAYER}! It's JAXON.\p"
	.string "I fell off my BIKE again. That slope!\p"
	.string "Luckily, {STR_VAR_3} caught me.$"
#endif

@ Glatzkopf Kaspar (TRAINER_CUE_BALL_ISAIAH), MAP_ROUTE17
MatchCall_Kanto_Isaiah_Battle::
#if GERMAN
	.string "Hey, Kiddie! Hier ist Kaspar!\p"
	.string "Ich bin mächtig stolz auf mein Team!\n"
	.string "Komm schon!\p"
	.string "Ich warte auf Route 17!$"
#else
	.string "Hey, kiddo! It's ISAIAH!\p"
	.string "I'm mighty proud of my team! Come on!\p"
	.string "I'm waiting on ROUTE 17!$"
#endif

MatchCall_Kanto_Isaiah_General::
#if GERMAN
	.string "Hey, Kiddie! Hier ist Kaspar.\p"
	.string "Ich hab heute mit {STR_VAR_3}\n"
	.string "Bauchplatscher geübt.\p"
	.string "Der ganze Radweg hat gebebt! Hahaha!$"
#else
	.string "Hey, kiddo! It's ISAIAH.\p"
	.string "I practiced belly-bumps with\n"
	.string "{STR_VAR_3} today.\p"
	.string "All of CYCLING ROAD shook! Hahaha!$"
#endif

@ Glatzkopf Hajo (TRAINER_CUE_BALL_COREY), MAP_ROUTE17
MatchCall_Kanto_Corey_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Hajo!\p"
	.string "Sei ein Rebell! Kämpf mit mir!\p"
	.string "Komm zu Route 17!$"
#else
	.string "Hey, {PLAYER}! It's COREY!\p"
	.string "Be a rebel! Battle me!\p"
	.string "Come to ROUTE 17!$"
#endif

MatchCall_Kanto_Corey_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Hajo.\p"
	.string "Mein {STR_VAR_3} hat heute nicht auf\n"
	.string "mich gehört.\p"
	.string "Ein echter Rebell! Ich bin so stolz!$"
#else
	.string "Hey, {PLAYER}! It's COREY.\p"
	.string "My {STR_VAR_3} wouldn't listen to me\n"
	.string "today.\p"
	.string "A true rebel! I'm so proud!$"
#endif

@ Vogelfänger Pascal (TRAINER_BIRD_KEEPER_WILTON), MAP_ROUTE18
MatchCall_Kanto_Wilton_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Pascal.\p"
	.string "Ich hab jede Wiese nach neuen Pokémon\n"
	.string "abgesucht. Das war nicht leicht…\p"
	.string "Komm zu Route 18!$"
#else
	.string "Hi, {PLAYER}! It's WILTON.\p"
	.string "I checked every grassy area for new\n"
	.string "POKéMON. It wasn't easy…\p"
	.string "Come to ROUTE 18!$"
#endif

MatchCall_Kanto_Wilton_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Pascal.\p"
	.string "Ich laufe immer noch zu Fuß durchs hohe\n"
	.string "Gras.\p"
	.string "{STR_VAR_3} fliegt einfach. Das ist\n"
	.string "unfair!$"
#else
	.string "Hi, {PLAYER}! It's WILTON.\p"
	.string "I'm still walking through tall grass on\n"
	.string "foot.\p"
	.string "{STR_VAR_3} just flies. That's not\n"
	.string "fair!$"
#endif

@ Vogelfänger Roman (TRAINER_BIRD_KEEPER_JACOB), MAP_ROUTE18
MatchCall_Kanto_Jacob_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Roman.\p"
	.string "Ich sag's dir: Route 18 ist mein Gebiet!\p"
	.string "Komm her, wenn du es mir abnehmen\n"
	.string "willst!$"
#else
	.string "Hey, {PLAYER}! It's JACOB.\p"
	.string "I'm telling you: ROUTE 18 is my turf!\p"
	.string "Come here if you want to take it from\n"
	.string "me!$"
#endif

MatchCall_Kanto_Jacob_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Roman.\p"
	.string "Heute hab ich mit {STR_VAR_3} wieder\n"
	.string "Pokémon gejagt.\p"
	.string "Mein Gebiet ist einfach das beste!$"
#else
	.string "Hey, {PLAYER}! It's JACOB.\p"
	.string "I went catching POKéMON with\n"
	.string "{STR_VAR_3} again today.\p"
	.string "My turf is simply the best!$"
#endif

@ Schwimmer Umberto (TRAINER_SWIMMER_MALE_MATTHEW), MAP_ROUTE19
MatchCall_Kanto_Matthew_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Umberto!\p"
	.string "Surfst du immer noch? Ich schwimme\n"
	.string "lieber!\p"
	.string "Komm zu Route 19, dann kämpfen wir!$"
#else
	.string "Hey, {PLAYER}! It's MATTHEW!\p"
	.string "Still surfing? I'd rather swim!\p"
	.string "Come to ROUTE 19 and let's battle!$"
#endif

MatchCall_Kanto_Matthew_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Umberto.\p"
	.string "Ich bin heute mit {STR_VAR_3} bis\n"
	.string "nach Fuchsania City geschwommen!\p"
	.string "Und wieder zurück!$"
#else
	.string "Hey, {PLAYER}! It's MATTHEW.\p"
	.string "I swam all the way to FUCHSIA CITY with\n"
	.string "{STR_VAR_3} today!\p"
	.string "And back again!$"
#endif

@ Schwimmer Kevin (TRAINER_SWIMMER_MALE_TONY), MAP_ROUTE19
MatchCall_Kanto_Tony_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}. Hier ist Kevin.\p"
	.string "Ich hab aufs Meer geschaut, um meine\n"
	.string "Niederlage zu vergessen.\p"
	.string "Es hat nicht geklappt! Komm zu\n"
	.string "Route 19!$"
#else
	.string "Hi, {PLAYER}. It's TONY.\p"
	.string "I looked at the sea to forget losing to\n"
	.string "you.\p"
	.string "It didn't work! Come to ROUTE 19!$"
#endif

MatchCall_Kanto_Tony_General::
#if GERMAN
	.string "Hallo, {PLAYER}. Hier ist Kevin.\p"
	.string "Ich sitze am Strand und schaue mit\n"
	.string "{STR_VAR_3} aufs Meer.\p"
	.string "Das beruhigt so schön…$"
#else
	.string "Hi, {PLAYER}. It's TONY.\p"
	.string "I'm on the beach, looking at the sea\n"
	.string "with {STR_VAR_3}.\p"
	.string "It's so calming…$"
#endif

@ Schwimmerin Alice (TRAINER_SWIMMER_FEMALE_ALICE), MAP_ROUTE19
MatchCall_Kanto_Alice_Battle::
#if GERMAN
	.string "Hi, {PLAYER}! Hier ist Alice!\p"
	.string "Schwimmen ist herrlich! Sonnenbrand\n"
	.string "nicht!\p"
	.string "Komm zu Route 19, bevor ich verbrenne!$"
#else
	.string "Hi, {PLAYER}! It's ALICE!\p"
	.string "Swimming's great! Sunburns aren't!\p"
	.string "Come to ROUTE 19 before I burn!$"
#endif

MatchCall_Kanto_Alice_General::
#if GERMAN
	.string "Hi, {PLAYER}! Hier ist Alice.\p"
	.string "Mein Freund ist endlich von den\n"
	.string "Seeschauminseln zurück!\p"
	.string "Er ist total durchgefroren.\n"
	.string "{STR_VAR_3} hat nur gelacht.$"
#else
	.string "Hi, {PLAYER}! It's ALICE.\p"
	.string "My boyfriend's finally back from\n"
	.string "SEAFOAM ISLANDS!\p"
	.string "He's frozen stiff. {STR_VAR_3} just\n"
	.string "laughed.$"
#endif

@ Schwimmer Manuel (TRAINER_SWIMMER_MALE_DARRIN), MAP_ROUTE20
MatchCall_Kanto_Darrin_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Manuel!\p"
	.string "Kannst du immer noch nicht schwimmen?\n"
	.string "Dann komm zu Route 20!\p"
	.string "Ich zeig dir, wie's geht!$"
#else
	.string "Hey, {PLAYER}! It's DARRIN!\p"
	.string "Still can't swim? Then come to ROUTE 20!\p"
	.string "I'll show you how it's done!$"
#endif

MatchCall_Kanto_Darrin_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Manuel.\p"
	.string "Ich hab versucht, auf {STR_VAR_3} zu\n"
	.string "reiten.\p"
	.string "Es ist einfach abgetaucht… Schwimmen\n"
	.string "ist doch besser!$"
#else
	.string "Hey, {PLAYER}! It's DARRIN.\p"
	.string "I tried riding on {STR_VAR_3}.\p"
	.string "It just dove under… Swimming is better\n"
	.string "after all!$"
#endif

@ Schwimmerin Melissa (TRAINER_SWIMMER_FEMALE_MELISSA), MAP_ROUTE20
MatchCall_Kanto_Melissa_Battle::
#if GERMAN
	.string "Hi, {PLAYER}! Hier ist Melissa.\p"
	.string "Ich bin bereit für einen Kampf! Komm zu\n"
	.string "Route 20!\p"
	.string "Danach schwimmen wir zur Zinnoberinsel!$"
#else
	.string "Hi, {PLAYER}! It's MELISSA.\p"
	.string "I'm ready for a battle! Come to\n"
	.string "ROUTE 20!\p"
	.string "Then we'll swim to CINNABAR!$"
#endif

MatchCall_Kanto_Melissa_General::
#if GERMAN
	.string "Hi, {PLAYER}! Hier ist Melissa.\p"
	.string "Im Pokémon-Labor auf der Zinnoberinsel\n"
	.string "untersuchen sie Fossilien.\p"
	.string "Mein {STR_VAR_3} fand das langweilig.\n"
	.string "Hihi!$"
#else
	.string "Hi, {PLAYER}! It's MELISSA.\p"
	.string "The POKéMON LAB on CINNABAR is\n"
	.string "studying fossils.\p"
	.string "My {STR_VAR_3} found it boring.\n"
	.string "Tee-hee!$"
#endif

@ Picknicker Marion (TRAINER_PICNICKER_MISSY), MAP_ROUTE20
MatchCall_Kanto_Missy_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Marion.\p"
	.string "Ich bin schon wieder von der\n"
	.string "Zinnoberinsel herübergeschwommen!\p"
	.string "Komm zu Route 20 für einen Kampf!$"
#else
	.string "Hi, {PLAYER}! It's MISSY.\p"
	.string "I swam here from CINNABAR ISLAND\n"
	.string "again!\p"
	.string "Come to ROUTE 20 for a battle!$"
#endif

MatchCall_Kanto_Missy_General::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Marion.\p"
	.string "Ich hab mich in die Pokémon-Villa\n"
	.string "getraut!\p"
	.string "Aber {STR_VAR_3} hatte Angst. Wir\n"
	.string "sind schnell wieder raus.$"
#else
	.string "Hi, {PLAYER}! It's MISSY.\p"
	.string "I dared to go into the POKéMON MANSION!\p"
	.string "But {STR_VAR_3} got scared. We got\n"
	.string "out fast.$"
#endif

@ Angler Alain (TRAINER_FISHERMAN_WADE), MAP_ROUTE21_NORTH
MatchCall_Kanto_Wade_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Alain.\p"
	.string "Ich hab wieder einen großen Fang\n"
	.string "gemacht! Willst du noch ein Match?\p"
	.string "Komm zu Route 21!$"
#else
	.string "Hey, {PLAYER}! It's WADE.\p"
	.string "I got a big haul again! Wanna go for it\n"
	.string "once more?\p"
	.string "Come to ROUTE 21!$"
#endif

MatchCall_Kanto_Wade_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Alain.\p"
	.string "Rate mal, was ich heute gefangen habe!\p"
	.string "…Richtig. Karpador. Schon wieder.$"
#else
	.string "Hey, {PLAYER}! It's WADE.\p"
	.string "Guess what I caught today!\p"
	.string "…Right. MAGIKARP. Again.$"
#endif

@ Geschwister Ewe&Tobi (TRAINER_SIS_AND_BRO_LIL_IAN), MAP_ROUTE21_NORTH
MatchCall_Kanto_LilIan_Battle::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Tobi.\p"
	.string "Meine Schwester ist immer noch faul!\n"
	.string "Hilf mir, sie in Form zu bringen!\p"
	.string "Komm zu Route 21!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "My sis is still a slob! Help me get her\n"
	.string "into shape!\p"
	.string "Come to ROUTE 21!$"
#endif

MatchCall_Kanto_LilIan_General::
#if GERMAN
	.string "Hallo, {PLAYER}… Hier ist Ewe.\p"
	.string "Ich hab heute den ganzen Tag mit\n"
	.string "{STR_VAR_3} gefaulenzt.\p"
	.string "Sag's bloß nicht meinem Bruder!$"
#else
	.string "Hi, {PLAYER}…\p"
	.string "I lazed around with {STR_VAR_3} all\n"
	.string "day today.\p"
	.string "Don't tell my brother!$"
#endif

@ Schwimmer Pedro (TRAINER_SWIMMER_MALE_JACK), MAP_ROUTE21_SOUTH
MatchCall_Kanto_Jack_Battle::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Pedro!\p"
	.string "Ich trainiere meine Pokémon dort, wo ich\n"
	.string "sie gefangen habe: im Meer!\p"
	.string "Komm zu Route 21!$"
#else
	.string "Hey, {PLAYER}! It's JACK!\p"
	.string "I train my POKéMON where I caught them:\n"
	.string "at sea!\p"
	.string "Come to ROUTE 21!$"
#endif

MatchCall_Kanto_Jack_General::
#if GERMAN
	.string "Hey, {PLAYER}! Hier ist Pedro.\p"
	.string "Ich hab {STR_VAR_3} draußen auf See\n"
	.string "trainiert.\p"
	.string "Die Wellen waren riesig! Aber wir haben\n"
	.string "durchgehalten!$"
#else
	.string "Hey, {PLAYER}! It's JACK.\p"
	.string "I trained {STR_VAR_3} far out at sea.\p"
	.string "The waves were huge! But we held on!$"
#endif

@ Schwimmer Thomas (TRAINER_SWIMMER_MALE_ROLAND), MAP_ROUTE21_SOUTH
MatchCall_Kanto_Roland_Battle::
#if GERMAN
	.string "Ahh, {PLAYER}! Hier ist Thomas!\p"
	.string "Genieße die Sonne und den Wind! Und\n"
	.string "einen Kampf!\p"
	.string "Komm zu Route 21!$"
#else
	.string "Ahh, {PLAYER}! It's ROLAND!\p"
	.string "Feel the sun and the wind! And a battle!\p"
	.string "Come to ROUTE 21!$"
#endif

MatchCall_Kanto_Roland_General::
#if GERMAN
	.string "Ahh, {PLAYER}! Hier ist Thomas.\p"
	.string "Ich hab mich mit Sonnencreme\n"
	.string "eingerieben. Und {STR_VAR_3} auch!\p"
	.string "Diesmal werde ich nicht geröstet!$"
#else
	.string "Ahh, {PLAYER}! It's ROLAND.\p"
	.string "I put on sunscreen. And on\n"
	.string "{STR_VAR_3} too!\p"
	.string "This time I won't get roasted!$"
#endif

@ Class texts: Teenager
MatchCall_Kanto_ClassYoungster_General1::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Ich hab heute mit {STR_VAR_3}\n"
	.string "trainiert, bis es dunkel war.\p"
	.string "Nächstes Mal mache ich es dir nicht so\n"
	.string "leicht!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "I trained with {STR_VAR_3} today\n"
	.string "until it got dark.\p"
	.string "I won't go easy on you next time!$"
#endif

MatchCall_Kanto_ClassYoungster_General2::
#if GERMAN
	.string "Yo, {PLAYER}!\p"
	.string "Mein {STR_VAR_3} hat heute drei\n"
	.string "Kämpfe hintereinander gewonnen!\p"
	.string "Ich glaube, wir werden langsam richtig\n"
	.string "gut!$"
#else
	.string "Yo, {PLAYER}!\p"
	.string "My {STR_VAR_3} won three battles in a\n"
	.string "row today!\p"
	.string "I think we're getting really good!$"
#endif

@ Class texts: Käfersammler
MatchCall_Kanto_ClassBugCatcher_General1::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Der Vertania-Wald ist voller cooler\n"
	.string "Käfer-Pokémon!\p"
	.string "Mein {STR_VAR_3} hat dort heute viele\n"
	.string "Freunde gefunden!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "VIRIDIAN FOREST is full of cool bug\n"
	.string "POKéMON!\p"
	.string "My {STR_VAR_3} made lots of friends\n"
	.string "there today!$"
#endif

MatchCall_Kanto_ClassBugCatcher_General2::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Weißt du, was toll ist? Käfer-Pokémon\n"
	.string "entwickeln sich ganz schnell!\p"
	.string "Mein {STR_VAR_3} wird bestimmt noch\n"
	.string "stärker!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "You know what's great? Bug POKéMON\n"
	.string "evolve really fast!\p"
	.string "I bet my {STR_VAR_3} will get even\n"
	.string "stronger!$"
#endif

@ Class texts: Göre
MatchCall_Kanto_ClassLass_General1::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Ich hab mein {STR_VAR_3} heute\n"
	.string "gebürstet. Jetzt glänzt es richtig!\p"
	.string "Hihi! Wir sehen viel besser aus als du!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "I brushed my {STR_VAR_3} today. Now\n"
	.string "it's all shiny!\p"
	.string "Tee-hee! We look way better than you!$"
#endif

MatchCall_Kanto_ClassLass_General2::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Ich hab heute schon wieder gegen einen\n"
	.string "Jungen gewonnen! Mit {STR_VAR_3}!\p"
	.string "Gegen dich klappt das auch noch!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "I beat another boy today! With\n"
	.string "{STR_VAR_3}!\p"
	.string "I'll beat you too, just wait!$"
#endif

@ Class texts: Picknicker
MatchCall_Kanto_ClassPicnicker_General1::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Ich mache gerade ein Picknick mit\n"
	.string "meinem {STR_VAR_3}.\p"
	.string "Draußen schmeckt alles doppelt so gut!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "I'm having a picnic with my\n"
	.string "{STR_VAR_3} right now.\p"
	.string "Everything tastes twice as good\n"
	.string "outdoors!$"
#endif

MatchCall_Kanto_ClassPicnicker_General2::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Heute bin ich mit {STR_VAR_3} über die\n"
	.string "Wiesen gerannt.\p"
	.string "Ich bin total außer Atem, aber es war\n"
	.string "super!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "I ran all over the fields with\n"
	.string "{STR_VAR_3} today.\p"
	.string "I'm totally out of breath, but it was\n"
	.string "great!$"
#endif

@ Class texts: Wanderer
MatchCall_Kanto_ClassHiker_General1::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Ich bin gerade auf einem Berg. Die Luft\n"
	.string "hier oben ist herrlich!\p"
	.string "{STR_VAR_3} und ich, wir sind in\n"
	.string "unserem Element!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "I'm up on a mountain right now. The air\n"
	.string "up here is great!\p"
	.string "{STR_VAR_3} and I are right at home!$"
#endif

MatchCall_Kanto_ClassHiker_General2::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Ich war im Museum in Marmoria City!\p"
	.string "Wusstest du, dass ganz Kanto einst\n"
	.string "unter Wasser stand? Wahahaha!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "I visited the PEWTER MUSEUM!\p"
	.string "Did you know all of KANTO was once\n"
	.string "under water? Wahahaha!$"
#endif

@ Class texts: Camper
MatchCall_Kanto_ClassCamper_General1::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Ich zelte gerade. {STR_VAR_3} hält\n"
	.string "Wache, während ich koche.\p"
	.string "So lässt es sich leben!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "I'm camping out right now. {STR_VAR_3}\n"
	.string "keeps watch while I cook.\p"
	.string "This is the life!$"
#endif

MatchCall_Kanto_ClassCamper_General2::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Letzte Nacht hat es geregnet und mein\n"
	.string "Zelt war ganz nass.\p"
	.string "Aber {STR_VAR_3} hat mich warm\n"
	.string "gehalten!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "It rained last night and my tent got\n"
	.string "soaked.\p"
	.string "But {STR_VAR_3} kept me warm!$"
#endif

@ Class texts: Mechaniker
MatchCall_Kanto_ClassEngineer_General1::
#if GERMAN
	.string "Hallo, {PLAYER}.\p"
	.string "Wir verlegen gerade neue Leitungen.\n"
	.string "{STR_VAR_3} liefert den Strom!\p"
	.string "Ganz schön praktisch, so ein Pokémon!$"
#else
	.string "Hello, {PLAYER}.\p"
	.string "We're laying new cables. {STR_VAR_3}\n"
	.string "provides the power!\p"
	.string "POKéMON sure are handy!$"
#endif

MatchCall_Kanto_ClassEngineer_General2::
#if GERMAN
	.string "Hallo, {PLAYER}.\p"
	.string "Ich hab gerade Mittagspause.\p"
	.string "Morgen prüfe ich wieder Leitungen.\n"
	.string "Immer schön auf Hochspannung achten!$"
#else
	.string "Hello, {PLAYER}.\p"
	.string "I'm on my lunch break right now.\p"
	.string "Tomorrow I'm checking cables again.\n"
	.string "Always watch out for live wires!$"
#endif

@ Class texts: Spieler
MatchCall_Kanto_ClassGamer_General1::
#if GERMAN
	.string "Yo, {PLAYER}!\p"
	.string "Kopf oder Zahl? Bei Kopf setze ich alles\n"
	.string "auf {STR_VAR_3}!\p"
	.string "…Zahl. Na, dann eben nächstes Mal!$"
#else
	.string "Yo, {PLAYER}!\p"
	.string "Heads or tails? On heads, I bet it all on\n"
	.string "{STR_VAR_3}!\p"
	.string "…Tails. Oh well, next time!$"
#endif

MatchCall_Kanto_ClassGamer_General2::
#if GERMAN
	.string "Yo, {PLAYER}!\p"
	.string "Das Leben ist ein Spiel. Und\n"
	.string "Pokémon-Kämpfe erst recht!\p"
	.string "Nächstes Mal setze ich alles auf Sieg!$"
#else
	.string "Yo, {PLAYER}!\p"
	.string "Life is one big game. And POKéMON\n"
	.string "battles even more so!\p"
	.string "Next time, I'm betting everything on a\n"
	.string "win!$"
#endif

@ Class texts: Pokémaniac
MatchCall_Kanto_ClassPokemaniac_General1::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Ich hab meiner Sammlung ein neues Foto\n"
	.string "von {STR_VAR_3} hinzugefügt!\p"
	.string "Seltene Pokémon sind einfach das\n"
	.string "Größte!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "I added a new photo of {STR_VAR_3} to\n"
	.string "my collection!\p"
	.string "Rare POKéMON are simply the best!$"
#endif

MatchCall_Kanto_ClassPokemaniac_General2::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Hast du schon mal ein Pokémon gesehen,\n"
	.string "das sonst keiner hat?\p"
	.string "Ich suche Tag und Nacht danach!\n"
	.string "Hehehe…$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "Have you ever seen a POKéMON nobody\n"
	.string "else has?\p"
	.string "I search for one day and night! Hehehe…$"
#endif

@ Class texts: Streber
MatchCall_Kanto_ClassSuperNerd_General1::
#if GERMAN
	.string "Hallo, {PLAYER}.\p"
	.string "Ich habe die Werte von {STR_VAR_3}\n"
	.string "genau analysiert.\p"
	.string "Meine Strategie ist jetzt perfekt.\n"
	.string "Theoretisch…$"
#else
	.string "Hello, {PLAYER}.\p"
	.string "I analyzed {STR_VAR_3}'s stats in\n"
	.string "detail.\p"
	.string "My strategy is perfect now. In theory…$"
#endif

MatchCall_Kanto_ClassSuperNerd_General2::
#if GERMAN
	.string "Hallo, {PLAYER}.\p"
	.string "Wusstest du, dass Gift-Attacken gegen\n"
	.string "Pflanzen-Pokémon sehr effektiv sind?\p"
	.string "Das sollte man wissen!$"
#else
	.string "Hello, {PLAYER}.\p"
	.string "Did you know POISON-type moves are\n"
	.string "super effective against GRASS types?\p"
	.string "You should be informed!$"
#endif

@ Class texts: Zwillinge
MatchCall_Kanto_ClassTwins_General1::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier sind Nora und Jo!\p"
	.string "Wir haben heute zusammen {STR_VAR_3}\n"
	.string "trainiert!\p"
	.string "Zwillings-Kraft ist einfach die beste!$"
#else
	.string "Hi, {PLAYER}! It's the twins!\p"
	.string "We trained {STR_VAR_3} together\n"
	.string "today!\p"
	.string "Twin power is the best!$"
#endif

MatchCall_Kanto_ClassTwins_General2::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Nora sagt Hallo! Jo sagt auch Hallo!\p"
	.string "Wir machen immer alles zu zweit. Hihi!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "We both say hi! At the same time!\p"
	.string "We always do everything together.\n"
	.string "Tee-hee!$"
#endif

@ Class texts: Biker
MatchCall_Kanto_ClassBiker_General1::
#if GERMAN
	.string "Yo, {PLAYER}!\p"
	.string "Der Radweg ist der beste. Nichts geht\n"
	.string "über den Wind im Gesicht!\p"
	.string "{STR_VAR_3} liebt das Tempo auch!$"
#else
	.string "Yo, {PLAYER}!\p"
	.string "CYCLING ROAD is the best. Nothing\n"
	.string "beats the wind in your face!\p"
	.string "{STR_VAR_3} loves the speed too!$"
#endif

MatchCall_Kanto_ClassBiker_General2::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Der Radweg bei Nacht ist etwas ganz\n"
	.string "Besonderes.\p"
	.string "Die Straßenlaternen und der Wind… Das\n"
	.string "ist Freiheit!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "CYCLING ROAD at night is something\n"
	.string "else.\p"
	.string "The streetlights and the wind… That's\n"
	.string "freedom!$"
#endif

@ Class texts: Angler
MatchCall_Kanto_ClassFisherman_General1::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Heute beißen sie wie verrückt! Gerade\n"
	.string "hing ein {STR_VAR_3} dran.\p"
	.string "Angeln ist ein Sport fürs ganze Leben!$"
#else
	.string "Hello, {PLAYER}!\p"
	.string "They're biting like crazy today! I just\n"
	.string "hooked a {STR_VAR_3}.\p"
	.string "Fishing is a lifelong passion!$"
#endif

MatchCall_Kanto_ClassFisherman_General2::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Erinnerst du dich an die Geheimnisse\n"
	.string "des Angelns?\p"
	.string "Geduld und ein guter Köder! Mehr\n"
	.string "braucht man nicht!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "Do you remember the secrets of\n"
	.string "fishing?\p"
	.string "Patience and good bait! That's all it\n"
	.string "takes!$"
#endif

@ Class texts: Rocker
MatchCall_Kanto_ClassRocker_General1::
#if GERMAN
	.string "Yo, {PLAYER}!\p"
	.string "Ich hab heute mit {STR_VAR_3} einen\n"
	.string "neuen Song geschrieben!\p"
	.string "Der Refrain ist echt elektrisierend!$"
#else
	.string "Yo, {PLAYER}!\p"
	.string "I wrote a new song with {STR_VAR_3}\n"
	.string "today!\p"
	.string "The chorus is totally electrifying!$"
#endif

MatchCall_Kanto_ClassRocker_General2::
#if GERMAN
	.string "Yo, {PLAYER}!\p"
	.string "Unser Konzert gestern war der\n"
	.string "Wahnsinn!\p"
	.string "Dauernd ist das Licht ausgefallen. War\n"
	.string "wohl zu viel Strom…$"
#else
	.string "Yo, {PLAYER}!\p"
	.string "Our gig last night was insane!\p"
	.string "The lights kept going out. Guess it was\n"
	.string "too much power…$"
#endif

@ Class texts: Junges Glück
MatchCall_Kanto_ClassYoungCouple_General1::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Wir gehen gerade mit {STR_VAR_3}\n"
	.string "spazieren.\p"
	.string "Ist das nicht romantisch?$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "We're out for a walk with {STR_VAR_3}.\p"
	.string "Isn't it romantic?$"
#endif

MatchCall_Kanto_ClassYoungCouple_General2::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Wir zwei trainieren jetzt jeden Tag\n"
	.string "zusammen.\p"
	.string "Gemeinsam sind wir unschlagbar! Na ja,\n"
	.string "fast…$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "The two of us train together every day\n"
	.string "now.\p"
	.string "Together we're unbeatable! Well,\n"
	.string "almost…$"
#endif

@ Class texts: Schönheit
MatchCall_Kanto_ClassBeauty_General1::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Ich war heute mit {STR_VAR_3} beim\n"
	.string "Friseur.\p"
	.string "Wir sehen beide einfach umwerfend aus!$"
#else
	.string "Hello, {PLAYER}!\p"
	.string "I went to the salon with {STR_VAR_3}\n"
	.string "today.\p"
	.string "We both look simply stunning!$"
#endif

MatchCall_Kanto_ClassBeauty_General2::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Im Kaufhaus von Prismania City gibt es\n"
	.string "neue Kleider.\p"
	.string "Ein schönes Pokémon braucht eine\n"
	.string "schöne Trainerin!$"
#else
	.string "Hello, {PLAYER}!\p"
	.string "The CELADON DEPT. STORE has new\n"
	.string "dresses.\p"
	.string "A pretty POKéMON needs a pretty\n"
	.string "TRAINER!$"
#endif

@ Class texts: Vogelfänger
MatchCall_Kanto_ClassBirdKeeper_General1::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Ich trainiere gerade mit {STR_VAR_3}\n"
	.string "auf einer Wiese.\p"
	.string "Vogel-Pokémon brauchen viel\n"
	.string "Auslauf!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "I'm training with {STR_VAR_3} out\n"
	.string "in a meadow.\p"
	.string "Bird POKéMON need lots of\n"
	.string "exercise!$"
#endif

MatchCall_Kanto_ClassBirdKeeper_General2::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Heute war das Wetter herrlich.\p"
	.string "Meine Vogel-Pokémon waren kaum zu\n"
	.string "halten!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "The weather was wonderful today.\p"
	.string "My bird POKéMON could hardly be held\n"
	.string "back!$"
#endif

@ Class texts: Mühlensippe
MatchCall_Kanto_ClassCrushKin_General1::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Eva.\p"
	.string "Mein Bruder trainiert gerade mit\n"
	.string "{STR_VAR_3}. Hundert Liegestütze!\p"
	.string "Ohne Disziplin geht gar nichts!$"
#else
	.string "Hi, {PLAYER}! It's the big sister.\p"
	.string "My brother's training with\n"
	.string "{STR_VAR_3}. A hundred push-ups!\p"
	.string "Nothing works without discipline!$"
#endif

MatchCall_Kanto_ClassCrushKin_General2::
#if GERMAN
	.string "Hallo, {PLAYER}!\p"
	.string "Unser Trainingsprogramm ist jetzt\n"
	.string "doppelt so lang.\p"
	.string "Mein Bruder jammert, aber er wird\n"
	.string "stärker!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "Our training menu is twice as long now.\p"
	.string "My brother whines, but he's getting\n"
	.string "stronger!$"
#endif

@ Class texts: Glatzkopf
MatchCall_Kanto_ClassCueBall_General1::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Ich hab heute mit {STR_VAR_3}\n"
	.string "trainiert, bis die Muskeln brannten!\p"
	.string "Kraft ist alles!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "I trained with {STR_VAR_3} today till\n"
	.string "my muscles burned!\p"
	.string "Power is everything!$"
#endif

MatchCall_Kanto_ClassCueBall_General2::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Ich hab Hunger! Ich könnte drei Teller\n"
	.string "Nudeln verdrücken!\p"
	.string "Danach bin ich bereit für den nächsten\n"
	.string "Kampf!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "I'm starving! I could eat three plates\n"
	.string "of noodles!\p"
	.string "Then I'm ready for the next battle!$"
#endif

@ Class texts: Schwimmer
MatchCall_Kanto_ClassSwimmerM_General1::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Ich bin heute mit {STR_VAR_3} um die\n"
	.string "Wette geschwommen.\p"
	.string "Ich hab verloren… Aber nur knapp!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "I raced {STR_VAR_3} in the water\n"
	.string "today.\p"
	.string "I lost… But only just!$"
#endif

MatchCall_Kanto_ClassSwimmerM_General2::
#if GERMAN
	.string "Hey, {PLAYER}!\p"
	.string "Das Meer ist heute ganz ruhig. Perfekt\n"
	.string "zum Schwimmen!\p"
	.string "Du solltest auch mal ohne Pokémon ins\n"
	.string "Wasser!$"
#else
	.string "Hey, {PLAYER}!\p"
	.string "The sea is really calm today. Perfect\n"
	.string "for swimming!\p"
	.string "You should try it without a POKéMON\n"
	.string "sometime!$"
#endif

@ Class texts: Schwimmerin
MatchCall_Kanto_ClassSwimmerF_General1::
#if GERMAN
	.string "Hi, {PLAYER}!\p"
	.string "Die Wellen sind heute toll! Meine\n"
	.string "Pokémon lieben das offene Meer.\p"
	.string "{STR_VAR_3} wird so schnell!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "The waves are great today! My POKéMON\n"
	.string "love swimming in the open sea.\p"
	.string "{STR_VAR_3} is getting so fast!$"
#endif

MatchCall_Kanto_ClassSwimmerF_General2::
#if GERMAN
	.string "Hi, {PLAYER}!\p"
	.string "Schwimmen mit Pokémon ist die beste\n"
	.string "Übung.\p"
	.string "Und danach ein Eis am Strand! Herrlich!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "Swimming with POKéMON is the best\n"
	.string "exercise.\p"
	.string "And then ice cream on the beach!\n"
	.string "Lovely!$"
#endif

@ Class texts: Geschwister
MatchCall_Kanto_ClassSisAndBro_General1::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Tobi.\p"
	.string "Ich hab Ewe heute mit {STR_VAR_3} zum\n"
	.string "Joggen geschleppt.\p"
	.string "Sie hat nach fünf Minuten aufgegeben…$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "I dragged my sis out jogging with\n"
	.string "{STR_VAR_3} today.\p"
	.string "She gave up after five minutes…$"
#endif

MatchCall_Kanto_ClassSisAndBro_General2::
#if GERMAN
	.string "Hallo, {PLAYER}! Hier ist Tobi.\p"
	.string "Wir sind heute um die Wette\n"
	.string "geschwommen.\p"
	.string "Ewe hat sich unterwegs auf\n"
	.string "{STR_VAR_3} ausgeruht… Typisch!$"
#else
	.string "Hi, {PLAYER}!\p"
	.string "We had a swimming race today.\p"
	.string "My sis took a rest on {STR_VAR_3}\n"
	.string "halfway… Typical!$"
#endif
