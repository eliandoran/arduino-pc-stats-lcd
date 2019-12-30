#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "src/config.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void setup()
{
    Serial.begin(SERIAL_BAUDRATE);
    Serial.println("Hello world");

    lcd.init();
    lcd.backlight();
    lcd.clear();
    lcd.print("Hello world.");
}

void loop()
{
	
}
