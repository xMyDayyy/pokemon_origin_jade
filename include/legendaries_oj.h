#ifndef GUARD_LEGENDARIES_OJ_H
#define GUARD_LEGENDARIES_OJ_H

// Legendary rules, see docs/origin_jade/DECISIONS.md, D-026.
bool32 IsLegendaryIdAvailable(u32 id);
bool16 IsLegendaryAvailable(void);          // Special: id in VAR_0x8004; result returned and in VAR_RESULT
void RecordLegendaryBattleOutcome(void);    // Special: id in VAR_0x8004, right after the battle
void ReviveDefeatedLegendaries(void);       // Special: after every league victory
void UpdateLegendaryFleeCooldowns(u16 days);
void RecordRoamerCaught(u16 species);

#endif // GUARD_LEGENDARIES_OJ_H
