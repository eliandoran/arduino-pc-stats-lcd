#pragma once

#include <LiquidCrystal_I2C.h>

#include "config.h"
#include "trace.h"

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

void LCD_Print(const char* text, int x, int y) {
    lcd.setCursor(x, y);
    lcd.print(text);
}

void LCD_Print(char ch, int x, int y) {
    lcd.setCursor(x, y);
    lcd.print(ch);
}

void LCD_PrintCentered(const char* text, int x, int y, int width) {
    int length = strlen(text);

    if (length > 0) {
        x += (width / 2 - length / 2);
        LCD_Print(text, x, y);
    }
}

void LCD_PrintCentered(const char* text, int y) {
    LCD_PrintCentered(text, 0, y, LCD_COLUMNS);
}

void LCD_PrintRight(const char* text, int y) {
    int length = strlen(text);

    if (length > 0) {
        int x = (LCD_COLUMNS - length);
        LCD_Print(text, x, y);
    }
}

void LCD_Clear() {
    lcd.clear();
}

void LCD_ClearLine(int x, int y, int width) {
    String emptyLine;
    for (int i=0; i<width; i++) {
        emptyLine += ' ';
    }
    LCD_Print(emptyLine.c_str(), x, y);
}

void LCD_SetCustomCharacter(byte charIndex, uint8_t charData[]) {
    lcd.createChar(charIndex, charData);
}

void LCD_DrawCustomCharacter(int charIndex, int x, int y) {
    lcd.setCursor(x, y);
    lcd.write(charIndex);
}

void LCD_Initialize() {
    lcd.init();
    lcd.backlight();
    LCD_Clear();

    TRACE("[LCD] Initialized.");
}