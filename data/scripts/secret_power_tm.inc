Route111_Text_MakingRoomUseTMToMakeYourOwn:
#if GERMAN
	.string "Was das ist?\n"
	.string "Was ich hier mache?\p"
	.string "Ich überlege, ob ich mir hier mein\n"
	.string "eigenes Refugium mit Hilfe einer\l"
	.string "Pokémon-Attacke einrichte.\p"
	.string "Genau! Ich gebe dir diese TM. Richte\n"
	.string "dir damit auch dein eigenes Reich ein!$"
#else
	.string "What's that?\n"
	.string "What am I doing?\p"
	.string "I'm thinking about making my own room\n"
	.string "here using a POKéMON move.\p"
	.string "I know! I'll give you this TM.\n"
	.string "Will you use it to make your own room?$"
#endif

Route111_Text_ExplainSecretPower:
#if GERMAN
	.string "Suche dir einen Baum, der aussieht, als\n"
	.string "ob er einige Äste verlieren würde.\p"
	.string "Setze davor Geheimpower ein. Einige\n"
	.string "Äste werden sich öffnen und du kannst\l"
	.string "dann den Baum hinaufklettern.\p"
	.string "Du findest dort einen großen Raum, den\n"
	.string "du nach eigenem Geschmack einrichten\l"
	.string "kannst.\p"
	.string "Das ist dein eigener geheimer Raum…\n"
	.string "Eine Geheimbasis!\p"
	.string "Du solltest dir auch eine einrichten.\p"
	.string "Du musst dir deine Geheimbasis nicht\n"
	.string "unbedingt in einem Baum einrichten.\p"
	.string "Setze Geheimpower an steinigen\n"
	.string "Wänden ein, die Einkerbungen haben.\p"
	.string "Ich schaue mich jetzt nach weiteren\n"
	.string "Orten um. Tschüss!$"
#else
	.string "Find a big tree that looks like it might\n"
	.string "drop some vines.\p"
	.string "Use SECRET POWER in front of the tree.\n"
	.string "Some vines should get free and drop\l"
	.string "down, so you can climb the tree.\p"
	.string "You'll find a lot of space for putting\n"
	.string "your favorite things.\p"
	.string "It'll be your own secret room…\n"
	.string "A SECRET BASE!\p"
	.string "You should make one, too.\p"
	.string "Another thing, you don't always have\n"
	.string "to make your SECRET BASE in a tree.\p"
	.string "Try using SECRET POWER on rock walls\n"
	.string "that have small indents in them.\p"
	.string "I'm going to look for other places, too.\n"
	.string "Okay, bye!$"
#endif

Route111_Text_DontWantThis:
#if GERMAN
	.string "Oh, das willst du nicht haben? Wenn du\n"
	.string "deine Meinung änderst, sag Bescheid.$"
#else
	.string "Oh, you don't want this?\n"
	.string "If you change your mind, tell me, okay?$"
#endif

Route111_Text_DontHaveAnyRoom:
#if GERMAN
	.string "Oh, dafür hast du keinen Platz mehr.\p"
	.string "Ich verwahre es für dich. Hol es dir\n"
	.string "später ab, einverstanden?$"
#else
	.string "Oh, you don't have any room for this.\p"
	.string "I'll hold on to it, so come back for it\n"
	.string "another time, okay?$"
#endif

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
#if IS_HNS
	@ Origin Jade: no second TM43 if the player already has it.
	checkitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, TRUE, Route111_EventScript_AlreadyHasSecretPower
#endif
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

#if IS_HNS
Route111_EventScript_AlreadyHasSecretPower::
	msgbox Route111_Text_AlreadyHaveSecretPowerHns, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_Text_AlreadyHaveSecretPowerHns:
#if GERMAN
	.string "Oh! Du hast die TM43, Geheimpower,\n"
	.string "ja selbst dabei!\p"
	.string "Dann weißt du ja, was zu tun ist:\n"
	.string "Setze sie an so einem Busch, einer\l"
	.string "Einbuchtung oder einem großen Baum\l"
	.string "ein - und du erhältst dein eigenes\l"
	.string "Geheimversteck!$"
#else
	.string "Oh! You carry TM43, SECRET POWER,\n"
	.string "yourself!\p"
	.string "Then you know what to do: use it\n"
	.string "on a clump like this, an indent, or\l"
	.string "a large tree - and you'll get your\l"
	.string "very own secret hideout!$"
#endif
#endif

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
