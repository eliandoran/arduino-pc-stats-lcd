#include <Arduino.h>
#include "util/trace.h"

void Command_Check() {
    if (Serial.available() < 1)
        return;

    String commandStr = Serial.readString();
    TRACE_VAL(String("Got command ") + commandStr);
}