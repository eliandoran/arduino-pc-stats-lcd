#include <Arduino.h>
#include "util/trace.h"
#include "limits.h"
#include "command.h"
#include "loop.h"

#define LOOP_DEFAULT_INTERVAL 500
#define LOOP_INNER_DELAY 50
//#define LOOP_TRACE_UPDATES

int currentInterval = LOOP_DEFAULT_INTERVAL;
long lastUpdateTime;
void (*currentPage)(void) = NULL;

void Loop_SetInterval(int interval) {
    currentInterval = interval;
}

void Loop_SetCurrentPage(void (*page)(void)) {
    currentPage = page;
    Loop_Invalidate();
}

void Loop_ResetInterval() {
    currentInterval = LOOP_DEFAULT_INTERVAL;
}

void Loop_Invalidate() {
    lastUpdateTime = -LOOP_DEFAULT_INTERVAL;
}

void Loop_Enter() {
    Loop_Invalidate();

    while (true) {        
        long currentTime = millis();

        // Update the current screen if needed.
        if ((currentTime - lastUpdateTime) > currentInterval && currentPage != NULL) {
            long startTime = millis();
            (*currentPage)();
            int duration = (int)(millis() - startTime);

            #ifdef LOOP_TRACE_UPDATES
            TRACE_VAL(String("[LOOP] Update at ") + millis() + " in " + duration);
            #endif

            lastUpdateTime = currentTime;
        }

        // Check if there are any updates on the serial port.
        Command_Check();

        delay(LOOP_INNER_DELAY);
    }
}