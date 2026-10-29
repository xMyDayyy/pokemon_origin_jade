Route22_NorthEntrance_Frlg_MapScripts::
	.byte 0

Route22_NorthEntrance_EventScript_BoulderBadgeGuard::
	lock
	faceplayer
	@ Origin Jade: needs the Earth Badge (badge 8).
	setvar VAR_TEMP_1, 8
	bufferstdstring STR_VAR_1, STDSTRING_EARTH_BADGE
	goto Route22_NorthEntrance_EventScript_BadgeGuard
	end

Route22_NorthEntrance_EventScript_BoulderBadgeGuardTrigger::
	lockall
	setvar VAR_TEMP_1, 8
	@ VAR_0x8009 = the guard's local id.
	setvar VAR_0x8009, 1
	bufferstdstring STR_VAR_1, STDSTRING_EARTH_BADGE
	goto Route23_EventScript_BadgeGuardTrigger
	end
