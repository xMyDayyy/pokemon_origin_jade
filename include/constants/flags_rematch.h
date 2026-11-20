#ifndef GUARD_CONSTANTS_FLAGS_REMATCH_H
#define GUARD_CONSTANTS_FLAGS_REMATCH_H

// =====================================================================
// PokeCom rematch block
//
// One flag window for the phone rematch state of every gRematchTable row.
// GetFlagPointer (src/event_data.c) maps it to SaveBlock1 rematchFlags.
//
//  - registered: the trainer is in the PokeCom (one bit per slot)
//  - armed:      the trainer wants a rematch (one bit per slot)
//  - misc:       other rematch/PokeCom flags (named below)
//
// A row's bit is its slot, not its enum index: RematchSlot()
// (src/battle_setup.c) maps REMATCH_* to a slot in the fixed range
// of the row's region. A region grows into its own spare slots without
// moving any other bit. Within a region the slot is the row's position,
// so rows are only appended. Never move a range; saves store the bits.
// =====================================================================

#define REMATCH_FLAGS_START                 0x3800

// Slot ranges, the same for the registered and the armed bits.
#define REMATCH_SLOT_JOHTO                  0x000
#define REMATCH_SLOT_JOHTO_COUNT            64
#define REMATCH_SLOT_HOENN                  0x040
#define REMATCH_SLOT_HOENN_COUNT            96
#define REMATCH_SLOT_KANTO                  0x0A0
#define REMATCH_SLOT_KANTO_COUNT            96
// 0x100-0x11F: reserve (e.g. Johto/Kanto leader phone rematches).
#define REMATCH_SLOT_RESERVE                0x100
#define REMATCH_SLOT_RESERVE_COUNT          32
// Wally (+0), the Hoenn leaders (+1..+8), the Elite Four (+9..+13).
#define REMATCH_SLOT_SPECIAL                0x120
#define REMATCH_SLOT_SPECIAL_COUNT          32
#define REMATCH_SLOT_COUNT                  320

#define REMATCH_REGISTERED_FLAGS_START      (REMATCH_FLAGS_START + 0x000)
#define REMATCH_REGISTERED_FLAGS_END        (REMATCH_REGISTERED_FLAGS_START + REMATCH_SLOT_COUNT - 1)
#define REMATCH_ARMED_FLAGS_START           (REMATCH_FLAGS_START + 0x140)
#define REMATCH_ARMED_FLAGS_END             (REMATCH_ARMED_FLAGS_START + REMATCH_SLOT_COUNT - 1)

// Other rematch/PokeCom flags. Append after the last one, never reuse a number.
#define REMATCH_MISC_FLAGS_START            (REMATCH_FLAGS_START + 0x280)
#define REMATCH_MISC_FLAGS_COUNT            64
#define REMATCH_MISC_FLAGS_END              (REMATCH_MISC_FLAGS_START + REMATCH_MISC_FLAGS_COUNT - 1)

// The player won a rematch against Carter (Route 14), set in CB2_EndRematchBattle.
#define FLAG_DEFEATED_CARTER_REMATCH        (REMATCH_MISC_FLAGS_START + 0)
// Elite Four in the PokeCom, set in the Champion's room.
#undef  FLAG_REGISTERED_SIDNEY
#define FLAG_REGISTERED_SIDNEY              (REMATCH_MISC_FLAGS_START + 1)
#undef  FLAG_REGISTERED_PHOEBE
#define FLAG_REGISTERED_PHOEBE              (REMATCH_MISC_FLAGS_START + 2)
#undef  FLAG_REGISTERED_GLACIA
#define FLAG_REGISTERED_GLACIA              (REMATCH_MISC_FLAGS_START + 3)
#undef  FLAG_REGISTERED_DRAKE
#define FLAG_REGISTERED_DRAKE               (REMATCH_MISC_FLAGS_START + 4)
#undef  FLAG_REGISTERED_WALLACE
#define FLAG_REGISTERED_WALLACE             (REMATCH_MISC_FLAGS_START + 5)
// HnS: the player has met Mr. Stone in Rustboro (his PokeNav contact).
#define FLAG_MET_MR_STONE                   (REMATCH_MISC_FLAGS_START + 6)
// HnS: Norman's call comes after VAR_HNS_NORMAN_CALL_STEPS steps outdoors.
#define FLAG_HNS_NORMAN_CALL_PENDING        (REMATCH_MISC_FLAGS_START + 7)
#define REMATCH_MISC_FLAGS_RESERVE_START    (REMATCH_MISC_FLAGS_START + 8)

#define REMATCH_FLAGS_END                   REMATCH_MISC_FLAGS_END
#define REMATCH_FLAGS_COUNT                 (REMATCH_FLAGS_END - REMATCH_FLAGS_START + 1)
#define REMATCH_FLAG_BYTES                  ((REMATCH_FLAGS_COUNT + 7) / 8)

// Temp flag (cleared on every map load): set by the Kanto gym leader rematch
// scripts (and Janine's and Blue's first battle) around trainerbattle_no_intro;
// the team gets the phone rematch level band.
#define FLAG_TEMP_KANTO_LEADER_REMATCH      FLAG_TEMP_D

// SaveBlock1 bytes of the rematch area (step counters, rematchFlags, reserve).
#define REMATCH_SAVE_AREA_SIZE              124

#endif // GUARD_CONSTANTS_FLAGS_REMATCH_H
