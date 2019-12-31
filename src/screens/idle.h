#include "../lcd.h"

void Screen_Idle() {
    LCD_PrintCentered("Time goes here", 0);
    LCD_PrintCentered("Date goes here", 1);
}