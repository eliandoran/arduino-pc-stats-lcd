#include "../rtc.h"

String DateTime_FormatTime(DateTime dateTime) {
    String output;
    output += dateTime.hour();
    output += TIME_SEPARATOR;
    output += dateTime.minute();
    output += TIME_SEPARATOR;
    output += dateTime.second();
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