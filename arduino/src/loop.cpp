#include <Arduino.h>
#include "util/trace.h"
#include "limits.h"
#include "command.h"
#include "loop.h"

#define LOOP_DEFAULT_INTERVAL 500
#define LOOP_INNER_DELAY 0
#define LOOP_TRACE_UPDATES

void (*currentPage)(bool) = NULL;
int currentInterval = LOOP_DEFAULT_INTERVAL;
long lastUpdateTime;
bool initialized;

void Loop_SetInterval(int interval) {
    currentInterval = interval;
}

void Loop_SetCurrentPage(void (*page)(bool)) {
    currentPage = page;
    Loop_Invalidate();
}

void Loop_ResetInterval() {
    currentInterval = LOOP_DEFAULT_INTERVAL;
}

void Loop_Invalidate() {
    lastUpdateTime = -LOOP_DEFAULT_INTERVAL;
    initialized = false;
    Loop_ResetInterval();
}

void Loop_Enter() {
    Loop_Invalidate();

    while (true) {        
        long currentTime = millis();

        // Update the current screen if needed.
        if ((currentTime - lastUpdateTime) > currentInterval && currentPage != NULL) {
            #ifdef LOOP_TRACE_UPDATES
            long startTime = millis();
            #endif

            (*currentPage)(initialized);            

            #ifdef LOOP_TRACE_UPDATES
            int duration = (int)(millis() - startTime);
            long now = millis();
            TRACE_VAL(String("[LOOP] Update at ") + now + " in " + duration + " after " + (now - lastUpdateTime) + " initialized: " + initialized);
            #endif

            initialized = true;
            lastUpdateTime = currentTime;
        }

        // Check if there are any updates on the serial port.
        long startTime = millis();
        Command_Check();
        int duration = (int)(millis() - startTime);
        if (duration > 10) {
            TRACE_VAL(String("[LOOP] Command check took ") + (millis() - startTime));
        }

        //delay(LOOP_INNER_DELAY);
    }
}