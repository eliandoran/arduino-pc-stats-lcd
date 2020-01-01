#include <Arduino.h>
#include <string.h>
#include "util/trace.h"
#include "command.h"

String serialBuffer;

void Command_Exec(String** args, int numArgs) {
    for (int i=0; i<numArgs; i++) {
        TRACE_VAL(String("[COMMAND] Arg ") + *args[i]);
    }
}

void Command_ParseExec(String command) {
    TRACE_VAL(String("[COMMAND] Got command ") + command)

    int pos = 0;
    int spaceIndex;
    
    command += ' ';
    
    String **args = (String**)malloc(sizeof(String*) * COMMAND_MAX_ARGS);
    int numArgs = 0;
    while ((spaceIndex = command.indexOf(' ', pos)) > -1 &&
            numArgs < COMMAND_MAX_ARGS) {
        String segment = command.substring(pos, spaceIndex);        
        pos = spaceIndex + 1;
        args[numArgs++] = new String(segment);
    }    

    Command_Exec(args, numArgs);

    for (int i=0; i<numArgs; i++)
        delete args[i];
    free(args);
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
