#pragma once

#include <Arduino.h>

void LCD_Print(const char* text, int x, int y);
void LCD_Print(char ch, int x, int y);
void LCD_PrintCentered(const char* text, int x, int y, int width);
void LCD_PrintCentered(const char* text, int y);
void LCD_PrintRight(const char* text, int y);
void LCD_Print(const String &text, int x, int y);
void LCD_PrintCentered(const String &text, int x, int y, int width);
void LCD_PrintCentered(const String &text, int y);
void LCD_PrintRight(const String &text, int y);
void LCD_Clear();
void LCD_ClearLine(int x, int y, int width);
void LCD_SetCustomCharacter(byte charIndex, uint8_t charData[]);
void LCD_DrawCustomCharacter(int charIndex, int x, int y);
void LCD_Initialize();