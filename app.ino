#include <Arduino.h>
#include <Wire.h>

#include <RTClib.h>

#include "src/config.h"
#include "src/trace.h"
#include "src/rtc.h"
#include "src/lcd.h"

#include "src/screens/idle.h"
#include "src/screens/cpu-gpu.h"

#include "src/ui/hprogress.h"

void setup()
{
    Trace_Initialize();    
    RTC_Initialize();
    LCD_Initialize();
    HProgress_Initialize();    
}

void loop()
{
	//Screen_Idle();    
    Screen_CPU_GPU();
}
