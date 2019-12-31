#include "../lcd.h"
#include "../rtc.h"
#include "../util/locale.h"

DateTime lastTime = DateTime(0);

void Screen_Idle() {        
    DateTime now = RTC_GetTime();

    // Display time
    String timeFormatted = Locale_FormatTime(now);
    LCD_PrintCentered(timeFormatted.c_str(), 0);

    // Display date
    if (now.day() != lastTime.day()) {
        String dateFormatted = Locale_FormatDate(now);    
        LCD_PrintCentered(dateFormatted.c_str(), 1);
    }

    lastTime = now;
    delay(1000);
}