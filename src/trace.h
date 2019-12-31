#pragma once

#include "config.h"
#define TRACE(str) (Serial.println(F(str)));
#define TRACE_VAL(val) (Serial.println(val));

void Trace_Initialize() {
    Serial.begin(SERIAL_BAUDRATE);
    TRACE("[TRACE] Serial port initialized");
}