#include <RTClib.h>
#include "config.h"

RTC_DS1307 rtc;

DateTime RTC_GetTime() {
    return rtc.now();
}

void RTC_SetTime(DateTime time) {
    Serial.println("[RTC] Adjusting time");
    rtc.adjust(time);
}

bool RTC_IsTimeSet() {
    DateTime currentTime = RTC_GetTime();
    return (currentTime.unixtime() > RTC_MINIMAL_TIMESTAMP.unixtime());
}

void RTC_Initialize() {
    if (rtc.begin()) {
        Serial.println("[RTC] Initialized successfully.");
    } else {
        Serial.println("[RTC] Unable to initialize.");
    }

    bool adjustTime = false;

    if (rtc.isrunning()) {
        Serial.println("[RTC] Is running.");
    } else {
        Serial.println("[RTC] Is not running.");
        adjustTime = true;
    }

    if (RTC_IsTimeSet()) {
        Serial.println("[RTC] Time is set.");
    } else {        
        Serial.println("[RTC] Time is not set.");
        adjustTime = true;        
    }

    if (adjustTime) {
        RTC_SetTime(RTC_MINIMAL_TIMESTAMP);
    }
}