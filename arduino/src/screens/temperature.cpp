#include "lcd.h"
#include "config.h"
#include "screens.h"
#include "registry.h"
#include "ui/characters.h"
#include "util/locale.h"

#define ICON_CPU 0
#define ICON_GPU 1
#define ICON_MOTHERBOARD 2
#define ICON_CELSIUS_DEGREE 3

int lastValues[3] = { -1, -1, -1 };

static void drawComponent(int icon, int registryIndex, int x, int width, bool initialized) {
    int temperature = Registry_GetValue(registryIndex);
    bool hasValue = Registry_IsSet(registryIndex);
    String temperatureStr = Locale_FormatTemperature(temperature, ICON_CELSIUS_DEGREE, hasValue);

    if (initialized && temperature == lastValues[icon]) {       
        return; 
    }

    LCD_DrawCustomCharacter(icon, x + width / 2, 0);    
    LCD_PrintCentered(temperatureStr, x, 1, width);

    lastValues[icon] = temperature;
}

void Screen_Temperature(bool initialized) {
    if (!initialized) {
        LCD_SetCustomCharacter(ICON_CPU, CHAR_CPU);
        LCD_SetCustomCharacter(ICON_GPU, CHAR_GPU);
        LCD_SetCustomCharacter(ICON_MOTHERBOARD, CHAR_MOTHERBOARD);
        LCD_SetCustomCharacter(ICON_CELSIUS_DEGREE, CHAR_CELSIUS_DEGREE);
    }

    int width = LCD_COLUMNS / 3;

    drawComponent(ICON_CPU, REGISTRY_TEMP_CPU, 0, width, initialized);
    drawComponent(ICON_GPU, REGISTRY_TEMP_GPU, 6, width, initialized);
    drawComponent(ICON_MOTHERBOARD, REGISTRY_TEMP_MOTHERBOARD, 12, width, initialized);
}