#pragma once

#include <RTClib.h>

String Locale_FormatTime(const DateTime &dateTime);
String Locale_FormatDate(const DateTime &dateTime);
String Locale_FormatTemperature(int tempCelsius, int celsiusIconIndex, bool hasValue);
String Locale_FormatPercentage(int value, bool hasValue);
String Locale_FormatFrequency(int freq, bool hasValue);
String Locale_FormatRotationalSpeed(int speed, bool hasValue);