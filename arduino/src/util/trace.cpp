#include <Arduino.h>
#include "util/trace.h"

void Trace_Initialize() {
    Serial.begin(SERIAL_BAUDRATE);
    TRACE("[TRACE] Serial port initialized");
}