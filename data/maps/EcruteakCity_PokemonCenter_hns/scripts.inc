EcruteakCity_PokemonCenter_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY_HNS
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
#if GERMAN
	.string "Hi, ich bin Bill. Und wer bist du?\p"
	.string "Hmm, {PLAYER}?\n"
	.string "Du bist gerade zum richtigen Zeitpunkt\l"
	.string "gekommen.$"
#else
	.string "Hi, I'm BILL. And who are you?\p"
	.string "Hmm, {PLAYER}, huh?\n"
	.string "You've come at the right time.$"
#endif

EcruteakCity_PokemonCenter1F_Text_Bill2:
#if GERMAN
	.string "Ich habe gerade mein Pokémon-\n"
	.string "Lagerungssystem fertig eingestellt.\p"
	.string "Du kennst doch den PC, den du\n"
	.string "zum Aufbewahren deiner Pokémon\p"
	.string "benutzt, oder?\p"
	.string "Diesen habe ich selbst entwickelt!\p"
	.string "Jetzt, wo ich diesen hier installiert\n"
	.string "habe, läuft mein PC in allen Pokécenter\l"
	.string "in Johto und Kanto.\p"
	.string "Ich muss schnell zurück nach\n"
	.string "Dukatia City und meine Leute sehen.\l"
	.string "Du kannst aber jederzeit vorbeikommen!\p"
	.string "Tschüss!$"
#else
	.string "I just finished adjustments on my\n"
	.string "POKéMON STORAGE SYSTEM.\p"
	.string "You know that PC you use to store\n"
	.string "all your POKéMON?\p"
	.string "I developed that myself!\p"
	.string "Now that I've installed this one,\n"
	.string "my PC is running at all\l"
	.string "POKéMON CENTERS in JOHTO and KANTO.\p"
	.string "I have to hurry on back to\n"
	.string "GOLDENROD and see my folks. Feel\l"
	.string "free to visit anytime!\p"
	.string "Buh-bye!$"
#endif

EcruteakCity_PokemonCenter1F_Text_PokefanM:
#if GERMAN
	.string "Sowohl der Tanz der Kimono-Girls\p"
	.string "als auch die Art, wie sie ihre Pokémon\n"
	.string "einsetzen, ist wunderbar!$"
#else
	.string "The way the KIMONO GIRLS dance is\n"
	.string "marvelous.\p"
	.string "Just like the way they use their\n"
	.string "POKéMON.$"
#endif

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
#if GERMAN
	.string "Du hoffst, hier mehr Kämpfe zu erleben,\n"
	.string "nicht wahr?\p"
	.string "Es gibt offensichtlich einen\p"
	.string "Ort, an dem sich Trainer treffen.\p"
	.string "Wo, fragst du?\p"
	.string "Kurz nach Oliviana City.$"
#else
	.string "You must be hoping to battle more\n"
	.string "people, right?\p"
	.string "There's apparently some place where\n"
	.string "trainers gather.\p"
	.string "Where, you ask?\p"
	.string "It's a little past OLIVINE CITY.$"
#endif

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
#if GERMAN
	.string "Jens, der Arenaleiter, ist sooo cool!\n"
	.string "Seine Pokémon sind auch total stark!$"
#else
	.string "MORTY, the GYM LEADER, is soooo\n"
	.string "cool.\p"
	.string "His POKéMON are really tough too.$"
#endif

EcruteakCity_PokemonCenter1F_Text_GymGuide:
#if GERMAN
	.string "Hm, der See des Zorns… das plötzliche\n"
	.string "Erscheinen des roten Garados…\l"
	.string "Da ist doch irgendwas im Busch!\l"
	.string "$"
#else
	.string "LAKE OF RAGE…\p"
	.string "The appearance of a GYARADOS\n"
	.string "swarm…\p"
	.string "I smell a conspiracy. I know it!$"
#endif

