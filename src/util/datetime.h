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
    output += dateTime.dayOfTheWeek();
    output += ", ";
    output += dateTime.month();
    output += ' ';
    output += dateTime.day();
    return output;
}