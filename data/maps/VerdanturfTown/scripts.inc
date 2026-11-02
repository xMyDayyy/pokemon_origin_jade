VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
#if IS_HNS
	setflag FLAG_HIDE_VERDANTURF_TOWN_CONTEST_REPORTER
#endif
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
#if GERMAN
	.string "Mein Papa hat mir das erzählt.\p"
	.string "Er sagt, der Tunnel sei voller scheuer\n"
	.string "Pokémon.\p"
	.string "Sie haben Angst vor lauten Geräuschen\n"
	.string "und machen einen Aufruhr.\p"
	.string "Daher musste das Tunnelprojekt\n"
	.string "gestoppt werden.\p"
	.string "Aber es gibt da einen Mann. Der ver-\n"
	.string "sucht, den Tunnel alleine zu graben.$"
#else
	.string "My papa told me.\p"
	.string "He says this tunnel is full of\n"
	.string "timid POKéMON.\p"
	.string "They get all scared of loud noise and\n"
	.string "make a big uproar.\p"
	.string "So they had to stop the big tunnel\n"
	.string "project.\p"
	.string "But there's one man. He's trying to dig\n"
	.string "the tunnel by himself!$"
#endif

VerdanturfTown_Text_ManDugTunnelForLove:
#if GERMAN
	.string "Da war ein Mann, der hat den Tunnel ganz\n"
	.string "alleine für die Frau seines Herzens\l"
	.string "gegraben.\p"
	.string "Ich habe das nie so ganz verstanden.\n"
	.string "Aber, hey, ich finde es trotzdem klasse.$"
#else
	.string "There was a man who dug a tunnel for\n"
	.string "a lady he loved.\p"
	.string "I don't really get it, but hey!$"
#endif

VerdanturfTown_Text_AirCleanHere:
#if GERMAN
	.string "Der Wind steht immer so günstig, dass\n"
	.string "die Asche vom Vulkan nie hierher geweht\l"
	.string "wird.\p"
	.string "Die Luft ist sauber und klar.\n"
	.string "Hier zu leben, hilft auch den schwachen\l"
	.string "und kränklichen Menschen.$"
#else
	.string "The way the winds blow, volcanic ash\n"
	.string "is never blown in this direction.\p"
	.string "The air is clean and delicious here.\n"
	.string "Living here should do wonders for even\l"
	.string "frail and sickly people.$"
#endif

VerdanturfTown_Text_MakeBattleTentDebut:
#if GERMAN
	.string "Meine Pokémon und ich haben gerade\n"
	.string "eine Gewinnserie.\p"
	.string "Daher werde ich nun meinen Auftritt\n"
	.string "im Kampfcamp haben.$"
#else
	.string "My POKéMON and I, we've been riding\n"
	.string "a hot winning streak.\p"
	.string "So I decided to make my BATTLE TENT\n"
	.string "debut in this town.$"
#endif

VerdanturfTown_Text_GuyTryingToBustThroughCave:
#if GERMAN
	.string "Siehst du die Höhle neben dem Pkmn-\n"
	.string "Supermarkt?\p"
	.string "Da ist ein Typ drin, der die Felsbrocken\n"
	.string "sprengen will, damit er auf die andere\l"
	.string "Seite gehen kann.\p"
	.string "Wäre das toll, wenn ich auch dort durch-\n"
	.string "gehen könnte… Ein Besuch in Metarost\l"
	.string "City wäre dann ganz einfach.$"
#else
	.string "Did you see the cave next to the\n"
	.string "POKéMON MART?\p"
	.string "There's a guy in there who's trying to\n"
	.string "bust up boulders so he can bust out\l"
	.string "through to the other side.\p"
	.string "It'd be great if we could go through…\n"
	.string "It'll make it easy to visit RUSTBORO.$"
#endif

VerdanturfTown_Text_EasyToGetToRustboroNow:
#if GERMAN
	.string "Die Höhle neben dem Pkmn-Supermarkt\n"
	.string "ist nun ein Tunnel zur anderen Seite.\l"
	.string "\p"
	.string "Das ist toll! Jetzt kommt man ganz\n"
	.string "einfach nach Metarost City, um\l"
	.string "Devon-waren zu kaufen.$"
#else
	.string "That cave next to the POKéMON MART\n"
	.string "is now a tunnel to the other side.\p"
	.string "It's great--it's easy to go shop for\n"
	.string "new DEVON products in RUSTBORO now.$"
#endif

VerdanturfTown_Text_TownSign:
#if GERMAN
	.string "Wiesenflur\p"
	.string "“Das vom Wind gestreichelte Hoch-\n"
	.string "land mit dem süßen Duft des Grases.”$"
#else
	.string "VERDANTURF TOWN\p"
	.string "“The windswept highlands with the\n"
	.string "sweet fragrance of grass.”$"
#endif

VerdanturfTown_Text_WandasHouse:
#if GERMAN
	.string "Heikes Haus$"
#else
	.string "WANDA'S HOUSE$"
#endif

VerdanturfTown_Text_BattleTentSign:
#if GERMAN
	.string "Kampfcamp Wiesenflur\n"
	.string "“Wo Kämpfe Eine Augenweide Sind”$"
#else
	.string "BATTLE TENT VERDANTURF SITE\n"
	.string "“Feast Your Eyes on Battles!”$"
#endif

VerdanturfTown_Text_RusturfTunnelSign:
#if GERMAN
	.string "Metaflurtunnel\n"
	.string "“Verbindet Metarost City und\p"
	.string "Wiesenflur.\n"
	.string "Das Tunnelprojekt wurde abgebrochen.”$"
#else
	.string "RUSTURF TUNNEL\n"
	.string "“Linking RUSTBORO and VERDANTURF\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"
#endif

