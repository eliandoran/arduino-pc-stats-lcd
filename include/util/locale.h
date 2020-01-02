#pragma once

#include <RTClib.h>

String Locale_FormatTime(DateTime dateTime);
String Locale_FormatDate(DateTime dateTime);
String Locale_FormatTemperature(int tempCelsius, int celsiusIconIndex, bool hasValue);