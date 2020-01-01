#include <Arduino.h>
#include <Wire.h>

#include <RTClib.h>

#include "src/config.h"
#include "src/trace.h"
#include "src/rtc.h"
#include "src/lcd.h"
#include "src/loop.h"

#include "src/screens/idle.h"

void setup()
{
    Trace_Initialize();    
    RTC_Initialize();
    LCD_Initialize();      

    void (*initialPage)(void) = &Screen_Idle;
    Loop_Enter(initialPage);
}

void loop()
{    
	
}
