#pragma once

#include <LiquidCrystal_I2C.h>

#include "config.h"
#include "trace.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void LCD_Initialize() {
    lcd.init();
    lcd.backlight();
    lcd.clear();    

    TRACE("[LCD] Initialized.");
}