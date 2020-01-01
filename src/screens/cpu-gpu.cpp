#include "lcd.h"
#include "screens.h"
#include "loop.h"
#include "ui/characters.h"
#include "ui/charmap.h"
#include "ui/hprogress.h"

#define ICON_CPU 0
#define ICON_GPU 1
#define ICON_CELSIUS 2

#define ICON_CELSIUS_STR "\x2"

void Screen_CPU_GPU(bool initialized) {
    if (!initialized) {
        Loop_SetInterval(500);

        randomSeed(millis());

        LCD_SetCustomCharacter(ICON_CPU, CHAR_CPU);
        LCD_SetCustomCharacter(ICON_GPU, CHAR_GPU);
        LCD_SetCustomCharacter(ICON_CELSIUS, CHAR_CELSIUS_DEGREE);

        HProgress_Initialize();
    }

    LCD_DrawCustomCharacter(ICON_CPU, 0, 0);
    LCD_DrawCustomCharacter(ICON_GPU, 0, 1);

    LCD_PrintRight("32" ICON_CELSIUS_STR, 0);
    LCD_PrintRight("42" ICON_CELSIUS_STR, 1);        

    HProgress_Draw(2, 0, 10, HProgress_GetValue(0, rand(), RAND_MAX));
    HProgress_Draw(2, 1, 10, HProgress_GetValue(0, rand(), RAND_MAX));
}