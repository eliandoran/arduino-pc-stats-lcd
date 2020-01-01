#pragma once

#include "trace.h"

#include "screens/idle.h"

void Loop_Enter() {
    void (*initialPage)(void) = &Screen_Idle;

    while (true) {        
        long startTime = millis();
        (*initialPage)();
        int duration = (int)(millis() - startTime);
        TRACE_VAL(String("[LOOP] Update at ") + millis() + " in " + duration);
    }
}