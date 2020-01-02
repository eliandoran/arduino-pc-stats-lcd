#include "rtc.h"
#include "config.h"

/*
 * Date format
 */
const char* DAYS_OF_THE_WEEK[] = {
    "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

const char* MONTHS[] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

String Locale_FormatTime(DateTime dateTime) {
    String output;
    uint8_t hour = dateTime.hour();
    uint8_t minute = dateTime.minute();
    uint8_t second = dateTime.second();

    if (hour < 10) output += '0';
    output += hour;
    output += TIME_SEPARATOR;

    if (minute < 10) output += '0';
    output += minute;
    output += TIME_SEPARATOR;

    if (second < 10) output += '0';    
    output += second;

    return output;
}

String Locale_FormatDate(DateTime dateTime) {
    String output;
    output += DAYS_OF_THE_WEEK[dateTime.dayOfTheWeek()];
    output += ", ";
    output += MONTHS[dateTime.month() - 1];
    output += ' ';
    output += dateTime.day();
    return output;
}

String Locale_FormatTemperature(int tempCelsius, int celsiusIconIndex, bool hasValue) {
    String output;
    if (hasValue) 
        output += tempCelsius;
    else
        output += "--";    
    output += (char)celsiusIconIndex;
    return output;
}

String Locale_FormatPercentage(int value, bool hasValue) {
    String output;
    if (hasValue)
        output += value;
    else
        output += "--";
    output += '%';
    return output;
}

String Locale_FormatFrequency(int freq, bool hasValue) {
    String output;
    if (hasValue)
        output += freq;
    else
        output += "----";
    output += " MHz";
    return output;
}

String Locale_FormatRotationalSpeed(int speed, bool hasValue) {
    String output;
    if (hasValue)
        output += speed;
    else
        output += "----";
    output += " RPM";
    return output;
}