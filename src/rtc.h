#include <RTClib.h>
#include "config.h"

RTC_DS1307 rtc;

void RTC_Initialize() {
    if (rtc.begin()) {
        Serial.println("[RTC] Initialized successfully.");
    } else {
        Serial.println("[RTC] Unable to initialize.");
    }

    if (rtc.isrunning()) {
        Serial.println("[RTC] Is not running.");
    } else {
        Serial.println("[RTC] Is running.");
    }    
}


DateTime RTC_GetTime() {
    return rtc.now();
}