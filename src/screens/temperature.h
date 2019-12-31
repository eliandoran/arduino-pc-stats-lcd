#include "../lcd.h"
#include "../ui/characters.h"

#define ICON_CPU 0
#define ICON_GPU 1
#define ICON_MOTHERBOARD 2

static void drawComponent(int icon, int temperature, int x, int width) {
    LCD_DrawCustomCharacter(icon, x + width / 2, 0);    

    String temperatureStr = String(temperature);
    LCD_PrintCentered(temperatureStr.c_str(), x, 1, width);
}

void Screen_Temperature() {
    LCD_SetCustomCharacter(ICON_CPU, CHAR_CPU);
    LCD_SetCustomCharacter(ICON_GPU, CHAR_GPU);
    LCD_SetCustomCharacter(ICON_MOTHERBOARD, CHAR_MOTHERBOARD);

    int width = LCD_COLUMNS / 3;

    drawComponent(ICON_CPU, 30, 0, width);
    drawComponent(ICON_GPU, 60, 6, width);
    drawComponent(ICON_MOTHERBOARD, 90, 12, width);    
}