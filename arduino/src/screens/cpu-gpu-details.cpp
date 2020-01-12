#include "registry.h"
#include "lcd.h"
#include "util/locale.h"
#include "screens.h"

#define NUM_COMPONENTS 2

const char *COMPONENT_NAMES[NUM_COMPONENTS] = {
    "CPU",
    "GPU"
};

int lastUsage[NUM_COMPONENTS];
int lastFreq[NUM_COMPONENTS];
int lastFan[NUM_COMPONENTS];

void Screen_Component_Detail(bool initialized, int componentIndex,
        int usageRegister, int freqRegister, int fanRegister) {
    if (!initialized) {
        lastUsage[componentIndex] = -1;
        lastFreq[componentIndex] = -1;
        lastFan[componentIndex] = -1;

        LCD_Print(COMPONENT_NAMES[componentIndex], 1, 0);
    }
    
    int curUsage = Registry_GetValue(usageRegister);
    int curFreq = Registry_GetValue(freqRegister);
    int curFan = Registry_GetValue(fanRegister);    

    if (curUsage != lastUsage[componentIndex]) {
        bool hasUsage = Registry_IsSet(usageRegister);
        LCD_Print(Locale_FormatPercentage(curUsage, hasUsage), 1, 1);
        lastUsage[componentIndex] = curUsage;
    }

    if (curFreq != lastFreq[componentIndex]) {
        bool hasCpuFreq = Registry_IsSet(freqRegister);
        LCD_PrintRight(Locale_FormatFrequency(curFreq, hasCpuFreq) + " ", 0);
        lastFreq[componentIndex] = curFreq;
    }

    if (curFan != lastFan[componentIndex]) {
        bool hasCpuFan = Registry_IsSet(fanRegister);
        LCD_PrintRight(Locale_FormatRotationalSpeed(curFan, hasCpuFan) + " ", 1);
        lastFan[componentIndex] = curFan;
    }
}

void Screen_CPU_Details(bool initialized) {
    Screen_Component_Detail(
        initialized,
        0,
        REGISTRY_CPU_USAGE,
        REGISTRY_CPU_FREQUENCY,
        REGISTRY_CPU_FAN_SPEED
    );
}

void Screen_GPU_Details(bool initialized) {
    Screen_Component_Detail(
        initialized,
        1,
        REGISTRY_GPU_USAGE,
        REGISTRY_GPU_FREQUENCY,
        REGISTRY_GPU_FAN_SPEED
    );
}