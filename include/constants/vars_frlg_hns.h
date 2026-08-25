#ifndef GUARD_CONSTANTS_VARS_FRLG_HNS_H
#define GUARD_CONSTANTS_VARS_FRLG_HNS_H

// Auto-generiert fuer den Kanto-Merge (test/kanto-start).
// SaveBlock1 hat nur noch 4 Byte frei, deshalb liegen diese Vars in
// SaveBlock3 (dort sind ~1.5 KB frei). Zugriff via GetVarPointer().
//
// Quellen: FRLG-Kartenskripte und Coord-/Objekt-Vars aus den map.json.

#define FRLG_VARS_START 0x4200
// Vorbereitung auf die Zukunft (vor Release): 64 Reserve-Vars fuer neue
// Szenen, Zaehler und Zustaende, frei ab (FRLG_VARS_START+0x80). Die
// Slots 0x7D bis 0x7F am alten Ende sind bereits vergeben. Nach dem
// Release ist diese Zahl eingefroren.
#define FRLG_VARS_COUNT 192
#define FRLG_VARS_END   (FRLG_VARS_START+FRLG_VARS_COUNT-1)

#undef  VAR_DEOXYS_INTERACTION_NUM
#define VAR_DEOXYS_INTERACTION_NUM                                       (FRLG_VARS_START+0x0)
#undef  VAR_DEOXYS_INTERACTION_STEP_COUNTER
#define VAR_DEOXYS_INTERACTION_STEP_COUNTER                              (FRLG_VARS_START+0x1)
#undef  VAR_ELEVATOR_FLOOR
#define VAR_ELEVATOR_FLOOR                                               (FRLG_VARS_START+0x2)
#undef  VAR_MAP_SCENE_CERULEAN_CITY_RIVAL
#define VAR_MAP_SCENE_CERULEAN_CITY_RIVAL                                (FRLG_VARS_START+0x3)
#undef  VAR_MAP_SCENE_CERULEAN_CITY_ROCKET
#define VAR_MAP_SCENE_CERULEAN_CITY_ROCKET                               (FRLG_VARS_START+0x4)
#undef  VAR_MAP_SCENE_CINNABAR_ISLAND_2
#define VAR_MAP_SCENE_CINNABAR_ISLAND_2                                  (FRLG_VARS_START+0x5)
#undef  VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE
#define VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE (FRLG_VARS_START+0x6)
#undef  VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL
#define VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL (FRLG_VARS_START+0x7)
#undef  VAR_MAP_SCENE_FIVE_ISLAND_LOST_CAVE_ROOM10
#define VAR_MAP_SCENE_FIVE_ISLAND_LOST_CAVE_ROOM10                       (FRLG_VARS_START+0x8)
#undef  VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS
#define VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS                        (FRLG_VARS_START+0x9)
#undef  VAR_MAP_SCENE_FOUR_ISLAND
#define VAR_MAP_SCENE_FOUR_ISLAND                                        (FRLG_VARS_START+0xA)
#undef  VAR_MAP_SCENE_ICEFALL_CAVE_BACK
#define VAR_MAP_SCENE_ICEFALL_CAVE_BACK                                  (FRLG_VARS_START+0xB)
#undef  VAR_MAP_SCENE_MT_EMBER_EXTERIOR
#define VAR_MAP_SCENE_MT_EMBER_EXTERIOR                                  (FRLG_VARS_START+0xC)
#undef  VAR_MAP_SCENE_MT_MOON_B2F
#define VAR_MAP_SCENE_MT_MOON_B2F                                        (FRLG_VARS_START+0xD)
#undef  VAR_MAP_SCENE_ONE_ISLAND_HARBOR
#define VAR_MAP_SCENE_ONE_ISLAND_HARBOR                                  (FRLG_VARS_START+0xE)
#undef  VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F
#define VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F                       (FRLG_VARS_START+0xF)
#undef  VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB
#define VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB                     (FRLG_VARS_START+0x10)
#undef  VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE
#define VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE                           (FRLG_VARS_START+0x11)
#undef  VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY
#define VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY                              (FRLG_VARS_START+0x12)
#undef  VAR_MAP_SCENE_PEWTER_CITY
#define VAR_MAP_SCENE_PEWTER_CITY                                        (FRLG_VARS_START+0x13)
#undef  VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F
#define VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F                              (FRLG_VARS_START+0x14)
#undef  VAR_MAP_SCENE_POKEMON_TOWER_2F
#define VAR_MAP_SCENE_POKEMON_TOWER_2F                                   (FRLG_VARS_START+0x15)
#undef  VAR_MAP_SCENE_POKEMON_TOWER_6F
#define VAR_MAP_SCENE_POKEMON_TOWER_6F                                   (FRLG_VARS_START+0x16)
#undef  VAR_MAP_SCENE_ROCKET_WAREHOUSE
#define VAR_MAP_SCENE_ROCKET_WAREHOUSE                                   (FRLG_VARS_START+0x17)
#undef  VAR_MAP_SCENE_ROUTE22
#define VAR_MAP_SCENE_ROUTE22                                            (FRLG_VARS_START+0x18)
#undef  VAR_MAP_SCENE_ROUTE24
#define VAR_MAP_SCENE_ROUTE24                                            (FRLG_VARS_START+0x19)
#undef  VAR_MAP_SCENE_ROUTE5_ROUTE6_ROUTE7_ROUTE8_GATES
#define VAR_MAP_SCENE_ROUTE5_ROUTE6_ROUTE7_ROUTE8_GATES                  (FRLG_VARS_START+0x1A)
#undef  VAR_MAP_SCENE_SAFFRON_CITY_DOJO
#define VAR_MAP_SCENE_SAFFRON_CITY_DOJO                                  (FRLG_VARS_START+0x1B)
#undef  VAR_MAP_SCENE_SEAFOAM_ISLANDS_B4F
#define VAR_MAP_SCENE_SEAFOAM_ISLANDS_B4F                                (FRLG_VARS_START+0x1C)
#undef  VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1
#define VAR_MAP_SCENE_SEVEN_ISLAND_HOUSE_ROOM1                           (FRLG_VARS_START+0x1D)
#undef  VAR_MAP_SCENE_SILPH_CO_11F
#define VAR_MAP_SCENE_SILPH_CO_11F                                       (FRLG_VARS_START+0x1E)
#undef  VAR_MAP_SCENE_SILPH_CO_7F
#define VAR_MAP_SCENE_SILPH_CO_7F                                        (FRLG_VARS_START+0x1F)
#undef  VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F
#define VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F                       (FRLG_VARS_START+0x20)
#undef  VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR
#define VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR                               (FRLG_VARS_START+0x21)
#undef  VAR_MAP_SCENE_THREE_ISLAND
#define VAR_MAP_SCENE_THREE_ISLAND                                       (FRLG_VARS_START+0x22)
#undef  VAR_MAP_SCENE_TWO_ISLAND
#define VAR_MAP_SCENE_TWO_ISLAND                                         (FRLG_VARS_START+0x23)
#undef  VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER
#define VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER                      (FRLG_VARS_START+0x24)
#undef  VAR_MAP_SCENE_VERMILION_CITY
#define VAR_MAP_SCENE_VERMILION_CITY                                     (FRLG_VARS_START+0x25)
#undef  VAR_MAP_SCENE_VICTORY_ROAD_1F
#define VAR_MAP_SCENE_VICTORY_ROAD_1F                                    (FRLG_VARS_START+0x26)
#undef  VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1
#define VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER1                           (FRLG_VARS_START+0x27)
#undef  VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2
#define VAR_MAP_SCENE_VICTORY_ROAD_2F_BOULDER2                           (FRLG_VARS_START+0x28)
#undef  VAR_MAP_SCENE_VICTORY_ROAD_3F
#define VAR_MAP_SCENE_VICTORY_ROAD_3F                                    (FRLG_VARS_START+0x29)
#undef  VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR
#define VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR                             (FRLG_VARS_START+0x2A)
#undef  VAR_MAP_SCENE_VIRIDIAN_CITY_MART
#define VAR_MAP_SCENE_VIRIDIAN_CITY_MART                                 (FRLG_VARS_START+0x2B)
#undef  VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN
#define VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN                              (FRLG_VARS_START+0x2C)
#undef  VAR_MASSAGE_COOLDOWN_STEP_COUNTER
#define VAR_MASSAGE_COOLDOWN_STEP_COUNTER                                (FRLG_VARS_START+0x2D)
#undef  VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER
#define VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER                          (FRLG_VARS_START+0x2E)

// Kanto-Merge: Johto-Orden als eigene Bitmaske (Kanto behaelt FLAG_BADGE0X_GET).
#define VAR_JOHTO_BADGES (FRLG_VARS_START+0x7F)

// Kanto-Merge: 0 = Startgespraech steht noch aus, 1 = gelaufen.
#define VAR_PALLET_HOUSE_INTRO (FRLG_VARS_START+0x7D)

// Kanto-Merge: Schrittzaehler fuer den Anruf der Mutter.
#define VAR_HNS_MOM_CALL_STEPS (FRLG_VARS_START+0x7E)

// Belegt: 0x2F von 0x80

#endif // GUARD_CONSTANTS_VARS_FRLG_HNS_H
