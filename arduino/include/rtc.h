#pragma once

#include <RTClib.h>

DateTime RTC_GetTime();
void RTC_SetTime(DateTime time);
bool RTC_IsTimeSet();
void RTC_Initialize();
