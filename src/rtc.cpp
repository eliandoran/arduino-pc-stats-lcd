#include <RTClib.h>
#include "config.h"
#include "util/trace.h"

RTC_DS1307 rtc;

DateTime RTC_GetTime() {
    return rtc.now();
}

void RTC_SetTime(DateTime time) {
    TRACE("[RTC] Adjusting time");
    rtc.adjust(time);
}

bool RTC_IsTimeSet() {
    DateTime currentTime = RTC_GetTime();
    return (currentTime.unixtime() > RTC_MINIMAL_TIMESTAMP.unixtime());
}

void RTC_Initialize() {
    if (rtc.begin()) {
        TRACE("[RTC] Initialized successfully.");
    } else {
        TRACE("[RTC] Unable to initialize.");
    }

    bool adjustTime = false;

    if (rtc.isrunning()) {
        TRACE("[RTC] Is running.");
    } else {
        TRACE("[RTC] Is not running.");
        adjustTime = true;
    }

    if (RTC_IsTimeSet()) {
        TRACE("[RTC] Time is set.");
    } else {        
        TRACE("[RTC] Time is not set.");
        adjustTime = true;        
    }

    if (adjustTime) {
        RTC_SetTime(RTC_MINIMAL_TIMESTAMP);
    }
}