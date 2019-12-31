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

void LCD_Print(const char* text, int x, int y) {
    lcd.setCursor(x, y);
    lcd.print(text);
}

void LCD_PrintCentered(const char* text, int y) {
    int length = strlen(text);

    if (length > 0) {
        int x = (LCD_COLUMNS / 2 - length / 2);    
        LCD_Print(text, x, y);
    }
}