MtSilver_1F_ItemRoom_hns_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtSilver_1F_ItemRoom_OnResume
	.byte 0

MtSilver_1F_ItemRoom_OnResume::
	setescapewarp MAP_MT_SILVER_OUTSIDE_HNS, 17, 8
	end

@ Origin Jade: HnS had it only on Route 49 in Sinjoh (locked, D-019).
MtSilver_1F_ItemRoom_EventScript_ItemTMRockClimb::
	finditem ITEM_TM_ROCK_CLIMB
	end
