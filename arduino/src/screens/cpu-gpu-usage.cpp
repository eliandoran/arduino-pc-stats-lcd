#include "util/locale.h"
#include "lcd.h"
#include "screens.h"
#include "loop.h"
#include "registry.h"
#include "ui/characters.h"
#include "ui/charmap.h"
#include "ui/hprogress.h"

#define ICON_CPU 0
#define ICON_GPU 1
#define ICON_CELSIUS 2

#define ICON_CELSIUS_STR "\x2"

void Screen_CPU_GPU_Usage(bool initialized) {
    if (!initialized) {
        Loop_SetInterval(500);

        LCD_SetCustomCharacter(ICON_CPU, CHAR_CPU);
        LCD_SetCustomCharacter(ICON_GPU, CHAR_GPU);
        LCD_SetCustomCharacter(ICON_CELSIUS, CHAR_CELSIUS_DEGREE);

        HProgress_Initialize();
    }

    // Display icons for CPU and GPU.
    LCD_DrawCustomCharacter(ICON_CPU, 0, 0);
    LCD_DrawCustomCharacter(ICON_GPU, 0, 1);        

    // Display an horizontal indicator of CPU and GPU usage.
    int cpuUsage = Registry_GetValue(REGISTRY_CPU_USAGE, 0);
    int gpuUsage = Registry_GetValue(REGISTRY_GPU_USAGE, 0);
    HProgress_Draw(2, 0, 10, HProgress_GetValue(0, cpuUsage, 100));
    HProgress_Draw(2, 1, 10, HProgress_GetValue(0, gpuUsage, 100));

    // Display the temperatures.
    bool hasCpuTemp = Registry_IsSet(REGISTRY_TEMP_CPU);
    bool hasGpuTemp = Registry_IsSet(REGISTRY_TEMP_GPU);
    int cpuTemp = Registry_GetValue(REGISTRY_TEMP_CPU);
    int gpuTemp = Registry_GetValue(REGISTRY_TEMP_GPU);
    String cpuTempStr = Locale_FormatTemperature(cpuTemp, ICON_CELSIUS, hasCpuTemp);
    String gpuTempStr = Locale_FormatTemperature(gpuTemp, ICON_CELSIUS, hasGpuTemp);
    LCD_PrintRight(cpuTempStr, 0);
    LCD_PrintRight(gpuTempStr, 1);        
}