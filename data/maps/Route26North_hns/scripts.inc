Route26North_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26North_OnTransition
	.byte 0

@ Kanto-Merge: Erster Johto-Boden hinter dem Torhaus. Ab hier zeigt die
@ Regionskarte die kombinierte Johto/Kanto-Ansicht statt nur Kanto.
Route26North_OnTransition::
	setflag FLAG_VISITED_JOHTO
	@ Kanto-Merge: Flugpunkt Route 26. Der Trigger auf (12,6) liegt zwar direkt
	@ unter dem Torhausausgang, laesst sich beim Hereinkommen aber umgehen.
	@ Beim Kartenwechsel gesetzt trifft es sicher.
	setflag FLAG_VISITED_RECEPTION_GATE
	end

Route26North_Trigger::
	setflag FLAG_VISITED_RECEPTION_GATE
	setvar VAR_TEMP_0, 1
	end
