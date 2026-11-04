#include "global.h"
#include "event_data.h"
#include "rtc.h"
#include "weekday_oj.h"

// Scripts compare the result with WEEKDAY_* from include/constants/siirtc.h.
void GetWeekday(void)
{
    gSpecialVar_Result = GetDayOfWeek();
}
