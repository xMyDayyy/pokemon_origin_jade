MtSilver_1F_MoltresRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_1F_MoltresRoom_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MtSilver_1F_MoltresRoom_OnResume
	.byte 0

MtSilver_1F_MoltresRoom_OnResume::
	setescapewarp MAP_MT_SILVER_OUTSIDE_HNS, 17, 8
	end

MtSilver_1F_MoltresRoom_OnTransition: 
	callnative SetTimeBasedEncounters
	setflag FLAG_HIDE_MOLTRES
	end


@ Origin Jade: this Moltres never spawns.
MtSilver_1F_MoltresRoom_EventScript_Moltres::
	setflag FLAG_HIDE_MOLTRES
	removeobject LOCALID_MTSILVER_MOLTRES
	end
