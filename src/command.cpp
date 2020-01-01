#include <Arduino.h>
#include <string.h>
#include "util/trace.h"

String serialBuffer;

void Command_ParseExec(String command) {
    TRACE_VAL(String("[COMMAND] Got command ") + command);
}

void Command_Check() {
    if (Serial.available() < 1)
        return;

    String inputStr = Serial.readString();
    serialBuffer += inputStr;
    
    int newLineIndex = serialBuffer.indexOf('\n');
    if (newLineIndex > 0) {
        String command = serialBuffer.substring(0, newLineIndex - 1);
        Command_ParseExec(command);
    } else {
        TRACE("Did not get newline!")
    }
}
