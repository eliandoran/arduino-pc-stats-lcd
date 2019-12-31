#include "../lcd.h"
#include "../ui/characters.h"
#include "../ui/charmap.h"
#include "../ui/hprogress.h"

#define ICON_CPU 0
#define ICON_GPU 1

void Screen_CPU_GPU() {
    LCD_SetCustomCharacter(ICON_CPU, CHAR_CPU);
    LCD_SetCustomCharacter(ICON_GPU, CHAR_GPU);

    LCD_DrawCustomCharacter(ICON_CPU, 0, 0);
    LCD_DrawCustomCharacter(ICON_GPU, 0, 1);

    LCD_PrintRight("32" CHAR_DEGREE_STR, 0);
    LCD_PrintRight("42" CHAR_DEGREE_STR, 1);
    
    HProgress_Draw(2, 0, 10, HProgress_GetValue(0, 50, 100));
    HProgress_Draw(2, 1, 10, HProgress_GetValue(0, 100, 100));
}