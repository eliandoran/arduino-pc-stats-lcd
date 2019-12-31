#pragma once

#include <LiquidCrystal_I2C.h>

#include "config.h"
#include "trace.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void LCD_Print(const char* text, int x, int y) {
    lcd.setCursor(x, y);
    lcd.print(text);
}

void LCD_Clear() {
    lcd.clear();
}

void LCD_ClearLine(int y) {
    String emptyLine;
    for (int i=0; i<LCD_COLUMNS; i++) {
        emptyLine += ' ';
    }
    LCD_Print(emptyLine.c_str(), 0, y);
}

void LCD_PrintCentered(const char* text, int y) {
    int length = strlen(text);

    if (length > 0) {
        int x = (LCD_COLUMNS / 2 - length / 2);    
        LCD_ClearLine(y);
        LCD_Print(text, x, y);
    }
}

void LCD_Initialize() {
    lcd.init();
    lcd.backlight();
    LCD_Clear();

    TRACE("[LCD] Initialized.");
}