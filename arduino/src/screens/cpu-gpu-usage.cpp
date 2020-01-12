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

int lastCpuUsage, lastGpuUsage;
int lastCpuTemp, lastGpuTemp;

void Screen_CPU_GPU_Usage(bool initialized) {
    if (!initialized) {
        Loop_SetInterval(500);

        LCD_SetCustomCharacter(ICON_CPU, CHAR_CPU);
        LCD_SetCustomCharacter(ICON_GPU, CHAR_GPU);
        LCD_SetCustomCharacter(ICON_CELSIUS, CHAR_CELSIUS_DEGREE);

        HProgress_Initialize();

        // Display icons for CPU and GPU.
        LCD_DrawCustomCharacter(ICON_CPU, 0, 0);
        LCD_DrawCustomCharacter(ICON_GPU, 0, 1);   
    }         

    // Display an horizontal indicator of CPU and GPU usage.
    int cpuUsage = Registry_GetValue(REGISTRY_CPU_USAGE, 0);
    if (cpuUsage != lastCpuUsage) {
        HProgress_Draw(2, 0, 10, HProgress_GetValue(0, cpuUsage, 100));
        lastCpuUsage = cpuUsage;
    }

    int gpuUsage = Registry_GetValue(REGISTRY_GPU_USAGE, 0);
    if (gpuUsage != lastGpuUsage) {
        HProgress_Draw(2, 1, 10, HProgress_GetValue(0, gpuUsage, 100));
        lastGpuUsage = gpuUsage;
    }

    // Display the temperatures.
    int cpuTemp = Registry_GetValue(REGISTRY_TEMP_CPU);
    if (cpuTemp != lastCpuTemp) {
        bool hasCpuTemp = Registry_IsSet(REGISTRY_TEMP_CPU);
        String cpuTempStr = Locale_FormatTemperature(cpuTemp, ICON_CELSIUS, hasCpuTemp);
        LCD_PrintRight(cpuTempStr, 0);
        lastCpuTemp = cpuTemp;
    }

    int gpuTemp = Registry_GetValue(REGISTRY_TEMP_GPU);
    if (gpuTemp != lastGpuTemp) {
        bool hasGpuTemp = Registry_IsSet(REGISTRY_TEMP_GPU);
        String gpuTempStr = Locale_FormatTemperature(gpuTemp, ICON_CELSIUS, hasGpuTemp);
        LCD_PrintRight(gpuTempStr, 1);        
        lastGpuTemp = gpuTemp;
    }
}