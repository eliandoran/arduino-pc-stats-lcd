#include <Arduino.h>
#include <Wire.h>

#include <RTClib.h>

#include "config.h"
#include "util/trace.h"

#include "rtc.h"
#include "lcd.h"
#include "storage.h"

#include "loop.h"
#include "navigator.h"

// cppcheck-suppress unusedFunction ; used by the Arduino bootloader
void setup()
{
    Trace_Initialize();
    Storage_Initialize();
    RTC_Initialize();
    LCD_Initialize();      

    Navigator_Start();

    TRACE("Ready.");

    Loop_Enter();
}

// cppcheck-suppress unusedFunction ; required by the Arduino bootloader
void loop()
{    
    // No action needed.
}
