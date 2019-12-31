#include "../lcd.h"
#include "../ui/characters.h"

#define ICON_CPU 0
#define ICON_GPU 1

void Screen_CPU_GPU() {
    LCD_SetCustomCharacter(ICON_CPU, CHAR_CPU);
    LCD_SetCustomCharacter(ICON_GPU, CHAR_GPU);

    LCD_DrawCustomCharacter(ICON_CPU, 0, 0);
    LCD_DrawCustomCharacter(ICON_GPU, 0, 1);

    LCD_PrintRight("32", 0);
    LCD_PrintRight("42", 1);
}