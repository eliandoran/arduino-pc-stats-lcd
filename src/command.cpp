#include <Arduino.h>
#include <string.h>
#include "util/trace.h"

String serialBuffer;

void Command_ParseExec(String command) {
    TRACE_VAL(String("[COMMAND] Got command ") + command)

    int pos = 0;
    int spaceIndex;
    
    command += ' ';
    while ((spaceIndex = command.indexOf(' ', pos)) > -1) {
        String segment = command.substring(pos, spaceIndex);
        TRACE_VAL(String("[COMMAND] Arg ") + segment);
        pos = spaceIndex + 1;
    }
}

void Command_Check() {
    if (Serial.available() < 1)
        return;

    String inputStr = Serial.readString();
    serialBuffer += inputStr;
    
    int newLineIndex = serialBuffer.indexOf('\n');
    if (newLineIndex > 0) {
        // Execute command if non-empty.
        if (newLineIndex > 1) {
            String command = serialBuffer.substring(0, newLineIndex - 1);
            Command_ParseExec(command);
        } else {
            TRACE("[COMMAND] Got a blank line.")
        }
        
        serialBuffer = serialBuffer.substring(newLineIndex + 1);
    } else {
        TRACE("[COMMAND] Did not get newline!")
    }
}
