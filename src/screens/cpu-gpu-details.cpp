#include "registry.h"
#include "lcd.h"
#include "util/locale.h"
#include "screens.h"

int lastCpuUsage;

void Screen_CPU_Details(bool initialized) {
    if (!initialized) {
        lastCpuUsage = -1;
    }
    
    int curCpuUsage = Registry_GetValue(REGISTRY_CPU_USAGE);
    
    LCD_Print("CPU", 1, 0);

    if (curCpuUsage != lastCpuUsage) {
        bool hasCpuUsage = Registry_IsSet(REGISTRY_CPU_USAGE);
        LCD_Print(Locale_FormatPercentage(curCpuUsage, hasCpuUsage), 1, 1);
    }
}