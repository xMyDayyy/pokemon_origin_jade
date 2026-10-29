Route26North_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26North_OnTransition
	.byte 0

@ First Johto map: unlocks the Johto/Kanto region map and the Route 26 fly point.
Route26North_OnTransition::
	setflag FLAG_VISITED_JOHTO
	setflag FLAG_VISITED_RECEPTION_GATE
	end

Route26North_Trigger::
	setflag FLAG_VISITED_RECEPTION_GATE
	setvar VAR_TEMP_0, 1
	end
