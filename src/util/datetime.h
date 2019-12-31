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