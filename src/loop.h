#pragma once

#include "trace.h"

#include "screens/idle.h"

void Loop_Enter() {
    void (*initialPage)(void) = &Screen_Idle;

    while (true) {
        TRACE_VAL(String("Update at ") + millis());
        (*initialPage)();
    }
}