#include <Arduino.h>
#include "util/trace.h"

void Trace_Initialize() {
    Serial.begin(SERIAL_BAUDRATE);
    Serial.setTimeout(10);
    TRACE("[TRACE] Serial port initialized");
}