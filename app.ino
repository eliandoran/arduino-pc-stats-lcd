#include <Arduino.h>
#include <Wire.h>

#include <LiquidCrystal_I2C.h>
#include <RTClib.h>

#include "src/config.h"
#include "src/trace.h"
#include "src/rtc.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup()
{
    Trace_Initialize();

    lcd.init();
    lcd.backlight();
    lcd.clear();    

    RTC_Initialize();
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
