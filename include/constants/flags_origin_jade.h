#ifndef GUARD_CONSTANTS_FLAGS_ORIGIN_JADE_H
#define GUARD_CONSTANTS_FLAGS_ORIGIN_JADE_H

// =====================================================================
// Origin Jade flag block
//
// All new Origin Jade flags go here, not into flags_hns.h or flags_hoenn_de.h.
// GetFlagPointer (src/event_data.c) redirects 0x2000-0x21FF into SaveBlock3.
// Sections: Kanto, Johto and Hoenn, each followed by 32 spare slots, then cross-region.
//
//  1. Append new flags to the end of their section, never into the spare slots.
//  2. Never reuse numbers: rename a dropped flag to FLAG_OJ_UNUSED_* and keep it.
//  3. Run tools/check_flags.py after every HnS merge.
//  4. Never move a section: saves store the numbers. When a section is
//     full, add a new section at the end and raise OJ_FLAGS_COUNT. The
//     block may grow up to 0x33FF.
// =====================================================================

#define OJ_FLAGS_START              0x2000
#define OJ_FLAGS_COUNT              512
#define OJ_FLAGS_END                (OJ_FLAGS_START + OJ_FLAGS_COUNT - 1)
#define OJ_NUM_FLAG_BYTES           ((OJ_FLAGS_COUNT + 7) / 8)

// Section starts as offsets from OJ_FLAGS_START.
#define OJ_FLAGS_KANTO              (OJ_FLAGS_START + 0)
#define OJ_FLAGS_KANTO_SIZE         96
#define OJ_FLAGS_JOHTO              (OJ_FLAGS_START + 128)
#define OJ_FLAGS_JOHTO_SIZE         160
#define OJ_FLAGS_HOENN              (OJ_FLAGS_START + 320)
#define OJ_FLAGS_HOENN_SIZE         96
#define OJ_FLAGS_GLOBAL             (OJ_FLAGS_START + 448)
#define OJ_FLAGS_GLOBAL_SIZE        64

// ---------------------------------------------------------------------
// Kanto (OJ_FLAGS_KANTO + 0 to + 95)
// ---------------------------------------------------------------------
// Item balls on Mt. Moon B3F.
#define FLAG_HIDE_MT_MOON_B3F_ITEM_BALL_1                    (OJ_FLAGS_KANTO + 0)
#define FLAG_HIDE_MT_MOON_B3F_ITEM_BALL_2                    (OJ_FLAGS_KANTO + 1)
#define FLAG_HIDE_MT_MOON_B3F_ITEM_BALL_3                    (OJ_FLAGS_KANTO + 2)
// Legendaries caught, see constants/legendaries_oj.h.
#define FLAG_CAUGHT_ARTICUNO                                 (OJ_FLAGS_KANTO + 3)
#define FLAG_CAUGHT_ZAPDOS                                   (OJ_FLAGS_KANTO + 4)
#define FLAG_CAUGHT_MOLTRES                                  (OJ_FLAGS_KANTO + 5)
#define FLAG_CAUGHT_MEWTWO                                   (OJ_FLAGS_KANTO + 6)
// Janina (Fuchsia gym leader after the league change) gave TM Poison Jab.
#define FLAG_GOT_TM_POISON_JAB_FROM_JANINE                   (OJ_FLAGS_KANTO + 7)
// Blue (Viridian gym leader after the league change) gave TM Trick Room.
#define FLAG_GOT_TM_TRICK_ROOM_FROM_BLUE                     (OJ_FLAGS_KANTO + 8)
// VS Seeker used: trainers in view want a rematch until it has recharged
// (I_VS_SEEKER_CHARGING, src/vs_seeker.c).
#define FLAG_VS_SEEKER_CHARGING                              (OJ_FLAGS_KANTO + 9)
// Hides Troy in Oak's lab; set again on every entry unless he waits there.
#define FLAG_HIDE_OAKS_LAB_TROY                              (OJ_FLAGS_KANTO + 10)
// Item balls with the TMs of HnS's Kanto.
#define FLAG_HIDE_ROUTE6_TM_SILVER_WIND                      (OJ_FLAGS_KANTO + 11)
#define FLAG_HIDE_ROUTE9_TM_FLASH_CANNON                     (OJ_FLAGS_KANTO + 12)
#define FLAG_HIDE_ROUTE10_TM_ROCK_POLISH                     (OJ_FLAGS_KANTO + 13)
#define FLAG_HIDE_ROUTE11_TM_GRASS_KNOT                      (OJ_FLAGS_KANTO + 14)
#define FLAG_HIDE_ROUTE19_TM_BRINE                           (OJ_FLAGS_KANTO + 15)
#define FLAG_HIDE_ROCK_TUNNEL_B1F_TM_FLING                   (OJ_FLAGS_KANTO + 16)
#define FLAG_HIDE_CELADON_CITY_TM_RECYCLE                    (OJ_FLAGS_KANTO + 17)
#define FLAG_HIDE_VIRIDIAN_FOREST_TM_PSYCH_UP                (OJ_FLAGS_KANTO + 18)
// TMs of HnS's Kanto given by FRLG trainers.
#define FLAG_GOT_TM_ROCK_SLIDE_FROM_BROCK                    (OJ_FLAGS_KANTO + 19)
#define FLAG_GOT_TM_STONE_EDGE_FROM_ROBERT                   (OJ_FLAGS_KANTO + 20)
#define FLAG_GOT_TM_WILL_O_WISP_FROM_BENNY                   (OJ_FLAGS_KANTO + 21)
#define FLAG_GOT_TM_ENERGY_BALL_FROM_GRACE                   (OJ_FLAGS_KANTO + 22)
// The player won a VS Seeker rematch against Carter (Route 14), set in CB2_EndRematchBattle.
#define FLAG_DEFEATED_CARTER_REMATCH                         (OJ_FLAGS_KANTO + 23)
#define FLAG_GOT_TM_THUNDER_WAVE_FROM_CARTER                 (OJ_FLAGS_KANTO + 24)
#define FLAG_GOT_TM_X_SCISSOR_FROM_RICK                      (OJ_FLAGS_KANTO + 25)
// TMs of HnS's Kanto from NPCs.
#define FLAG_GOT_TM_EXPLOSION_UNDERGROUND_PATH               (OJ_FLAGS_KANTO + 26)
#define FLAG_GOT_TM_SLEEP_TALK_CELADON_ROOF                  (OJ_FLAGS_KANTO + 27)
// Hidden items and item balls with items that had no other source.
#define FLAG_HIDDEN_ITEM_VERMILION_CITY_PEARL_STRING_FRLG    (OJ_FLAGS_KANTO + 28)
#define FLAG_HIDDEN_ITEM_CERULEAN_CAVE_B1F_ODD_INCENSE_FRLG  (OJ_FLAGS_KANTO + 29)
#define FLAG_HIDDEN_ITEM_ROUTE15_ROSE_INCENSE_FRLG           (OJ_FLAGS_KANTO + 30)
#define FLAG_HIDDEN_ITEM_MT_MOON_B2F_COMET_SHARD             (OJ_FLAGS_KANTO + 31)
#define FLAG_HIDDEN_ITEM_CERULEAN_CITY_BERSERK_GENE          (OJ_FLAGS_KANTO + 32)
#define FLAG_HIDDEN_ITEM_ROUTE8_FAIRY_GEM_FRLG               (OJ_FLAGS_KANTO + 33)
#define FLAG_HIDE_MT_MOON_1F_FAIRY_FEATHER                   (OJ_FLAGS_KANTO + 34)
// Bill gave the Pokemon Box Link after the Kanto title.
#define FLAG_RECEIVED_POKEMON_BOX_LINK                       (OJ_FLAGS_KANTO + 35)
// Celadon's game designer gave the Catching Charm with the Kanto diploma.
#define FLAG_RECEIVED_CATCHING_CHARM                         (OJ_FLAGS_KANTO + 36)

// ---------------------------------------------------------------------
// Johto (OJ_FLAGS_JOHTO + 0 to + 159)
// ---------------------------------------------------------------------
// Set once Lance has been beaten (Johto counterpart to FLAG_IS_HOENN_CHAMPION).
#define FLAG_IS_JOHTO_CHAMPION                       (OJ_FLAGS_JOHTO + 0)
// Received the Johto starter from Elm's lab.
#define FLAG_RECEIVED_JOHTO_STARTER                  (OJ_FLAGS_JOHTO + 1)
// Johto start values set on the first visit to New Bark Town.
#define FLAG_JOHTO_ARRIVAL_DONE                      (OJ_FLAGS_JOHTO + 2)
// VAR_JOHTO_STARTER_MON save migration done (see LoadGameSave in src/save.c).
#define FLAG_MIGRATED_JOHTO_STARTER_VAR              (OJ_FLAGS_JOHTO + 3)
// Radio tower quiz in Goldenrod won: hides Whitney there, no new quiz, turns on
// the Johto radio programmes.
#define FLAG_WON_GOLDENROD_RADIO_QUIZ                (OJ_FLAGS_JOHTO + 4)
// Goldenrod flag heap save migration done (see LoadGameSave in src/save.c).
#define FLAG_MIGRATED_GOLDENROD_FLAG_HEAP            (OJ_FLAGS_JOHTO + 5)
// Johto berry slot save migration done (see LoadGameSave in src/save.c).
#define FLAG_MIGRATED_JOHTO_BERRY_SLOTS              (OJ_FLAGS_JOHTO + 6)
// One-time encounters, see constants/legendaries_oj.h. CAUGHT: never back;
// DEFEATED: caught or knocked out, cleared after a league victory unless caught.
#define FLAG_DEFEATED_CELEBI                         (OJ_FLAGS_JOHTO + 7)
#define FLAG_CAUGHT_SUICUNE                          (OJ_FLAGS_JOHTO + 8)
#define FLAG_DEFEATED_SUICUNE                        (OJ_FLAGS_JOHTO + 9)
#define FLAG_CAUGHT_UNION_CAVE_LAPRAS                (OJ_FLAGS_JOHTO + 10)
#define FLAG_DEFEATED_UNION_CAVE_LAPRAS              (OJ_FLAGS_JOHTO + 11)
#define FLAG_CAUGHT_RED_GYARADOS                     (OJ_FLAGS_JOHTO + 12)
#define FLAG_DEFEATED_RED_GYARADOS                   (OJ_FLAGS_JOHTO + 13)
// A Day Care man gave the Oval Charm with the first egg.
#define FLAG_RECEIVED_OVAL_CHARM                     (OJ_FLAGS_JOHTO + 14)
// The Violet City gift egg hatched, whatever its species (Elm's lab).
#define FLAG_HATCHED_TOGEPI_EGG                      (OJ_FLAGS_JOHTO + 15)
// Items without another source.
#define FLAG_HIDE_MT_SILVER_ITEM_ROOM_TM_ROCK_CLIMB  (OJ_FLAGS_JOHTO + 16)
#define FLAG_HIDE_ICE_PATH_1F_ICY_ROCK               (OJ_FLAGS_JOHTO + 17)
#define FLAG_HIDDEN_ITEM_ILEX_BIG_BAMBOO_SHOOT       (OJ_FLAGS_JOHTO + 18)
#define FLAG_HIDDEN_ITEM_ILEX_TINY_BAMBOO_SHOOT      (OJ_FLAGS_JOHTO + 19)
#define FLAG_HIDDEN_ITEM_ECRUTEAK_POKESHI_DOLL       (OJ_FLAGS_JOHTO + 20)
// Lilycove's game designer gave the EXP. Charm with the Johto diploma.
#define FLAG_RECEIVED_EXP_CHARM                      (OJ_FLAGS_JOHTO + 21)
// Hoenn hidden items; hidden-item flags must lie below FLAG_HIDDEN_ITEMS_START + 8192.
#define FLAG_HIDDEN_ITEM_ROUTE111_RARE_BONE          (OJ_FLAGS_JOHTO + 22)
#define FLAG_HIDDEN_ITEM_ROUTE111_SMOOTH_ROCK        (OJ_FLAGS_JOHTO + 23)
#define FLAG_HIDDEN_ITEM_FIERY_PATH_HEAT_ROCK        (OJ_FLAGS_JOHTO + 24)
#define FLAG_HIDDEN_ITEM_ROUTE119_DAMP_ROCK          (OJ_FLAGS_JOHTO + 25)
#define FLAG_HIDDEN_ITEM_SKY_PILLAR_OUTSIDE_SOUL_DEW (OJ_FLAGS_JOHTO + 26)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_RELIC_COPPER (OJ_FLAGS_JOHTO + 27)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_RELIC_SILVER (OJ_FLAGS_JOHTO + 28)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_RELIC_GOLD   (OJ_FLAGS_JOHTO + 29)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_RELIC_VASE   (OJ_FLAGS_JOHTO + 30)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_RELIC_BAND   (OJ_FLAGS_JOHTO + 31)
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_RELIC_STATUE (OJ_FLAGS_JOHTO + 32)
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_RELIC_CROWN  (OJ_FLAGS_JOHTO + 33)
// Snowball in Ice Path; HnS had it only in New Sinjoh (locked).
#define FLAG_HIDDEN_ITEM_ICE_PATH_B3F_SNOWBALL       (OJ_FLAGS_JOHTO + 34)
// The S.S. Aqua grandpa still owes the Metal Coat: the bag was full at the reunion.
#define FLAG_SSAQUA_METAL_COAT_PENDING               (OJ_FLAGS_JOHTO + 35)

// ---------------------------------------------------------------------
// Hoenn (OJ_FLAGS_HOENN + 0 to + 95)
// ---------------------------------------------------------------------
// Hoenn flags moved off numbers that HnS flags use.
#undef  FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380   (OJ_FLAGS_HOENN + 0)
#undef  FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE
#define FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE                  (OJ_FLAGS_HOENN + 1)
#undef  FLAG_HIDE_MARINE_CAVE_KYOGRE
#define FLAG_HIDE_MARINE_CAVE_KYOGRE                         (OJ_FLAGS_HOENN + 2)
#undef  FLAG_UNKNOWN_0x363
#define FLAG_UNKNOWN_0x363                                   (OJ_FLAGS_HOENN + 3)
#undef  FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2  (OJ_FLAGS_HOENN + 4)
#undef  FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD
#define FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD                   (OJ_FLAGS_HOENN + 5)
#undef  FLAG_HIDE_FANCLUB_OLD_LADY
#define FLAG_HIDE_FANCLUB_OLD_LADY                           (OJ_FLAGS_HOENN + 6)
#undef  FLAG_HIDE_FANCLUB_BOY
#define FLAG_HIDE_FANCLUB_BOY                                (OJ_FLAGS_HOENN + 7)
#undef  FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON
#define FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON       (OJ_FLAGS_HOENN + 8)
#undef  FLAG_HIDE_MAUVILLE_CITY_SCOTT
#define FLAG_HIDE_MAUVILLE_CITY_SCOTT                        (OJ_FLAGS_HOENN + 9)
#undef  FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
#define FLAG_HIDE_CHAMPIONS_ROOM_RIVAL                       (OJ_FLAGS_HOENN + 10)
#undef  FLAG_HIDE_CHAMPIONS_ROOM_BIRCH
#define FLAG_HIDE_CHAMPIONS_ROOM_BIRCH                       (OJ_FLAGS_HOENN + 11)
#undef  FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE
#define FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE                    (OJ_FLAGS_HOENN + 12)
#undef  FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE
#define FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE                    (OJ_FLAGS_HOENN + 13)
#undef  FLAG_HIDE_LILYCOVE_MOTEL_GAME_DESIGNERS
#define FLAG_HIDE_LILYCOVE_MOTEL_GAME_DESIGNERS              (OJ_FLAGS_HOENN + 14)
#undef  FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
#define FLAG_HIDE_METEOR_FALLS_TEAM_AQUA                     (OJ_FLAGS_HOENN + 15)
#undef  FLAG_HIDE_ROUTE_128_STEVEN
#define FLAG_HIDE_ROUTE_128_STEVEN                           (OJ_FLAGS_HOENN + 16)

// Trainer flags of Hoenn trainers whose flag id would land on the daily or
// engine flags. TrainerIdToFlagId (src/battle_setup.c) redirects them here.
#define OJ_TRAINER_FLAGS_DAILY                               (OJ_FLAGS_HOENN + 17)
#define OJ_TRAINER_FLAGS_ENGINE                              (OJ_TRAINER_FLAGS_DAILY + NUM_DAILY_FLAGS)
#define OJ_TRAINER_FLAGS_HOENN_END                           (OJ_TRAINER_FLAGS_ENGINE + NUM_ENGINE_FLAGS - 1)
// Rydel's Mach/Acro Bike in Mauville (FLAG_RECEIVED_BIKE is the Johto bike).
#define FLAG_RECEIVED_HOENN_BIKE                             (OJ_TRAINER_FLAGS_HOENN_END + 1)
// Legendaries caught, see constants/legendaries_oj.h.
#define FLAG_CAUGHT_REGIROCK                                 (OJ_TRAINER_FLAGS_HOENN_END + 2)
#define FLAG_CAUGHT_REGICE                                   (OJ_TRAINER_FLAGS_HOENN_END + 3)
#define FLAG_CAUGHT_REGISTEEL                                (OJ_TRAINER_FLAGS_HOENN_END + 4)
#define FLAG_CAUGHT_GROUDON                                  (OJ_TRAINER_FLAGS_HOENN_END + 5)
#define FLAG_CAUGHT_KYOGRE                                   (OJ_TRAINER_FLAGS_HOENN_END + 6)
#define FLAG_CAUGHT_RAYQUAZA                                 (OJ_TRAINER_FLAGS_HOENN_END + 7)
#define FLAG_CAUGHT_LATIAS                                   (OJ_TRAINER_FLAGS_HOENN_END + 8)
#define FLAG_CAUGHT_LATIOS                                   (OJ_TRAINER_FLAGS_HOENN_END + 9)
// First Hoenn title done: the end credits rolled. Later Hoenn titles skip them.
#define FLAG_ROLLED_ENDING_CREDITS                           (OJ_TRAINER_FLAGS_HOENN_END + 10)
// The game designer in Lilycove's Cove Lily Motel gave the Shiny Charm.
#define FLAG_RECEIVED_SHINY_CHARM                            (OJ_TRAINER_FLAGS_HOENN_END + 11)
// Mr. Stone's PokeNav scene at Devon done (FLAG_RECEIVED_POKENAV is Mom's PokeCom).
#define FLAG_HOENN_RECEIVED_POKENAV                          (OJ_TRAINER_FLAGS_HOENN_END + 12)
// May registered on Route 104; she waits there until Rustboro or Dewford.
#define FLAG_HOENN_REGISTER_RIVAL_POKENAV                    (OJ_TRAINER_FLAGS_HOENN_END + 13)
// Norman's Surf license given; Wally's parents talk about Wally having left.
#define FLAG_HOENN_RECEIVED_HM_SURF                          (OJ_TRAINER_FLAGS_HOENN_END + 14)
// Talked to Mauville's Rock Smash man; hides the hint man on Route 111.
#define FLAG_HOENN_RECEIVED_HM_ROCK_SMASH                    (OJ_TRAINER_FLAGS_HOENN_END + 15)
// Devon revived a fossil; read by the Fossil Maniac on Route 114.
#define FLAG_HOENN_RECEIVED_REVIVED_FOSSIL_MON               (OJ_TRAINER_FLAGS_HOENN_END + 16)
// Rusturf Tunnel cleared; read by the PokeNav calls of Mr. Stone and the rival.
#define FLAG_HOENN_RECEIVED_HM_STRENGTH                      (OJ_TRAINER_FLAGS_HOENN_END + 17)
// Lilycove's lottery ticket drawn today; cleared by ClearDailyFlags.
#define FLAG_HOENN_PICKED_LOTO_TICKET                        (OJ_TRAINER_FLAGS_HOENN_END + 18)
// Jirachi on Route 4, see constants/legendaries_oj.h. CAUGHT: never back;
// DEFEATED: caught or knocked out, cleared after a league victory unless caught.
#define FLAG_CAUGHT_JIRACHI                                  (OJ_TRAINER_FLAGS_HOENN_END + 19)
#define FLAG_DEFEATED_JIRACHI                                (OJ_TRAINER_FLAGS_HOENN_END + 20)

// ---------------------------------------------------------------------
// Cross-region (OJ_FLAGS_GLOBAL + 0 to + 63)
// ---------------------------------------------------------------------
// Johto species unlocked: first Johto map after the Kanto title.
#define FLAG_JOHTO_UNLOCKED                          (OJ_FLAGS_GLOBAL + 0)
// Contest reporters in the Verdanturf and Fallarbor contest lobbies.
#define FLAG_HIDE_VERDANTURF_TOWN_CONTEST_REPORTER   (OJ_FLAGS_GLOBAL + 1)
#define FLAG_HIDE_FALLARBOR_TOWN_CONTEST_REPORTER    (OJ_FLAGS_GLOBAL + 2)
// TM Attract from the girl in Verdanturf's contest lobby.
#define FLAG_HOENN_RECEIVED_TM_ATTRACT               (OJ_FLAGS_GLOBAL + 3)
// TM Torment from the sailor in Slateport's contest hall.
#define FLAG_HOENN_RECEIVED_TM_TORMENT               (OJ_FLAGS_GLOBAL + 4)

// ---------------------------------------------------------------------
// Not saved: special flags (RAM, src/event_data.c), cleared by a new game
// and kept across warps. HnS uses SPECIAL_FLAGS_START + 0x00 to + 0x05;
// append from + 0x06 on, up to SPECIAL_FLAGS_END.
// ---------------------------------------------------------------------
// Hoenn ship trip that goes on from the Route 104 pier to Birch's lab.
#define FLAG_HOENN_SHIP_TO_BIRCHS_LAB                (SPECIAL_FLAGS_START + 0x06)

#endif // GUARD_CONSTANTS_FLAGS_ORIGIN_JADE_H
