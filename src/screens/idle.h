#include "../lcd.h"
#include "../rtc.h"
#include "../util/datetime.h"

void Screen_Idle() {        
    DateTime now = RTC_GetTime();
    String timeFormatted = DateTime_FormatTime(now);
    String dateFormatted = DateTime_FormatDate(now);

    LCD_PrintCentered(timeFormatted.c_str(), 0);
    LCD_PrintCentered(dateFormatted.c_str(), 1);

    delay(1000);
}