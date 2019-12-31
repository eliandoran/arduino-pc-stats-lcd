#include "../rtc.h"

String DateTime_FormatTime(DateTime dateTime) {
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

String DateTime_FormatDate(DateTime dateTime) {
    String output;
    output += DAYS_OF_THE_WEEK[dateTime.dayOfTheWeek()];
    output += ", ";
    output += MONTHS[dateTime.month() - 1];
    output += ' ';
    output += dateTime.day();
    return output;
}