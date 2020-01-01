#include <Arduino.h>
#include <Wire.h>

#include <RTClib.h>

#include "config.h"
#include "util/trace.h"
#include "rtc.h"
#include "lcd.h"
#include "loop.h"
#include "navigator.h"

void setup()
{
    Trace_Initialize();    
    RTC_Initialize();
    LCD_Initialize();      

    Navigator_Start();
    Loop_Enter();
}

void loop()
{    
	
}
