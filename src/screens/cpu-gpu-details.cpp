#include "registry.h"
#include "lcd.h"
#include "util/locale.h"
#include "screens.h"

int lastCpuUsage;
int lastCpuFreq;

void Screen_CPU_Details(bool initialized) {
    if (!initialized) {
        lastCpuUsage = -1;
        lastCpuFreq = -1;
    }
    
    int curCpuUsage = Registry_GetValue(REGISTRY_CPU_USAGE);
    int curCpuFreq = Registry_GetValue(REGISTRY_CPU_FREQUENCY);
    
    LCD_Print("CPU", 1, 0);

    if (curCpuUsage != lastCpuUsage) {
        bool hasCpuUsage = Registry_IsSet(REGISTRY_CPU_USAGE);
        LCD_Print(Locale_FormatPercentage(curCpuUsage, hasCpuUsage), 1, 1);
        lastCpuUsage = curCpuUsage;
    }

    if (curCpuFreq != lastCpuFreq) {
        bool hasCpuFreq = Registry_IsSet(REGISTRY_CPU_FREQUENCY);
        LCD_PrintRight(Locale_FormatClockSpeed(curCpuFreq, hasCpuFreq) + " ", 0);
        lastCpuFreq = curCpuFreq;
    }
}