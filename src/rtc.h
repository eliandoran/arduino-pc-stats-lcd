#include <RTClib.h>
#include "config.h"

RTC_DS1307 rtc;

DateTime RTC_GetTime() {
    return rtc.now();
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

    if (rtc.isrunning()) {
        Serial.println("[RTC] Is not running.");
    } else {
        Serial.println("[RTC] Is running.");
    }

    if (RTC_IsTimeSet()) {
        Serial.println("[RTC] Time is set.");
    } else {
        Serial.println("[RTC] Time is not set.");
    }
}