#include <Arduino.h>
#include <Wire.h>

#include <RTClib.h>

#include "src/config.h"
#include "src/trace.h"
#include "src/rtc.h"
#include "src/lcd.h"

void setup()
{
    Trace_Initialize();    
    RTC_Initialize();
    LCD_Initialize();
}

void loop()
{
	DateTime time = RTC_GetTime();

    Serial.print(time.day());
    Serial.print("/");
    Serial.print(time.month());
    Serial.print("/");
    Serial.print(time.year());
    Serial.print(" ");

    Serial.print(time.hour());
    Serial.print(":");
    Serial.print(time.minute());
    Serial.print(":");
    Serial.print(time.second());
    Serial.println();
    delay(1000);
}
