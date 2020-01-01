#include "../lcd.h"
#include "../rtc.h"
#include "../loop.h"
#include "../util/locale.h"

DateTime lastTime = DateTime(0);

void Screen_Idle() {        
    Loop_SetInterval(1000);

    DateTime now = RTC_GetTime();

    // Display time
    String timeFormatted = Locale_FormatTime(now);
    LCD_PrintCentered(timeFormatted, 0);

    // Display date
    if (now.day() != lastTime.day()) {
        String dateFormatted = Locale_FormatDate(now);    
        LCD_PrintCentered(dateFormatted, 1);
    }

    lastTime = now;
}