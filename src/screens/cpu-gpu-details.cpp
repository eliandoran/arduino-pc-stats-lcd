#include "registry.h"
#include "lcd.h"
#include "util/locale.h"
#include "screens.h"

int lastCpuUsage;
int lastCpuFreq;
int lastCpuFan;

void Screen_CPU_Details(bool initialized) {
    if (!initialized) {
        lastCpuUsage = -1;
        lastCpuFreq = -1;
        lastCpuFan = -1;
    }
    
    int curCpuUsage = Registry_GetValue(REGISTRY_CPU_USAGE);
    int curCpuFreq = Registry_GetValue(REGISTRY_CPU_FREQUENCY);
    int curCpuFan = Registry_GetValue(REGISTRY_CPU_FAN_SPEED);
    
    LCD_Print("CPU", 1, 0);

    if (curCpuUsage != lastCpuUsage) {
        bool hasCpuUsage = Registry_IsSet(REGISTRY_CPU_USAGE);
        LCD_Print(Locale_FormatPercentage(curCpuUsage, hasCpuUsage), 1, 1);
        lastCpuUsage = curCpuUsage;
    }

    if (curCpuFreq != lastCpuFreq) {
        bool hasCpuFreq = Registry_IsSet(REGISTRY_CPU_FREQUENCY);
        LCD_PrintRight(Locale_FormatFrequency(curCpuFreq, hasCpuFreq) + " ", 0);
        lastCpuFreq = curCpuFreq;
    }

    if (curCpuFan != lastCpuFan) {
        bool hasCpuFan = Registry_IsSet(REGISTRY_CPU_FAN_SPEED);
        LCD_PrintRight(Locale_FormatRotationalSpeed(curCpuFan, hasCpuFan) + " ", 1);
        lastCpuFan = curCpuFan;
    }
}