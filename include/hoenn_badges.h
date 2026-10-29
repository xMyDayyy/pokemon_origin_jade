#ifndef GUARD_HOENN_BADGES_H
#define GUARD_HOENN_BADGES_H

u32 GetHoennBadgeCount(void);
bool32 HasHoennBadge(u32 index);
void SetHoennBadge(void);      // Special: index in gSpecialVar_0x8004
void CountHoennBadges(void);   // Special: count into gSpecialVar_Result
void CheckHoennBadge(void);    // Special: index in gSpecialVar_0x8004, result into gSpecialVar_Result

#endif // GUARD_HOENN_BADGES_H
