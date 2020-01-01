#pragma once

#include "trace.h"
#include "limits.h"
#include "command.h"

#define LOOP_DEFAULT_INTERVAL 500
#define LOOP_INNER_DELAY 50

int currentInterval = LOOP_DEFAULT_INTERVAL;
long lastUpdateTime = -LOOP_DEFAULT_INTERVAL;
void (*currentPage)(void) = NULL;

void Loop_SetInterval(int interval) {
    currentInterval = interval;
}

void Loop_SetCurrentPage(void (*page)(void)) {
    currentPage = page;
}

void Loop_ResetInterval() {
    currentInterval = LOOP_DEFAULT_INTERVAL;
}

void Loop_Enter() {
    while (true) {        
        long currentTime = millis();

        // Update the current screen if needed.
        if ((currentTime - lastUpdateTime) > currentInterval && currentPage != NULL) {
            long startTime = millis();
            TRACE("Start update");
            (*currentPage)();
            int duration = (int)(millis() - startTime);
            TRACE_VAL(String("[LOOP] Update at ") + millis() + " in " + duration);

            lastUpdateTime = currentTime;
        }

        // Check if there are any updates on the serial port.
        Command_Check();

        delay(LOOP_INNER_DELAY);
    }
}