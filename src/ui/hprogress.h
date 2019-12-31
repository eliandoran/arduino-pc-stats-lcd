#pragma once

#include "characters.h"
#include "../lcd.h"
#include "../trace.h"

#define INDEX_HPROGRESS_20  7
#define INDEX_HPROGRESS_40  6
#define INDEX_HPROGRESS_60  5
#define INDEX_HPROGRESS_80  4
#define INDEX_HPROGRESS_100 3

void HProgress_Initialize() {
    LCD_SetCustomCharacter(INDEX_HPROGRESS_20,  CHAR_HPROGRESS_20);
    LCD_SetCustomCharacter(INDEX_HPROGRESS_40,  CHAR_HPROGRESS_40);
    LCD_SetCustomCharacter(INDEX_HPROGRESS_60,  CHAR_HPROGRESS_60);
    LCD_SetCustomCharacter(INDEX_HPROGRESS_80,  CHAR_HPROGRESS_80);
    LCD_SetCustomCharacter(INDEX_HPROGRESS_100, CHAR_HPROGRESS_100);
}

void HProgress_Draw(int x, int y, int width, byte value) {
    int numPixels = (((float)value / 255) * width * LCD_CHAR_WIDTH);
    int numFullSegments = (numPixels / LCD_CHAR_WIDTH);
    
    TRACE_VAL(value);
    TRACE_VAL(width);
    TRACE_VAL(numPixels);
    TRACE_VAL(numFullSegments);

    for (int i=0; i<numFullSegments; i++) {
        LCD_DrawCustomCharacter(INDEX_HPROGRESS_100, x, y);
        x++;
    }
}

byte HProgress_GetValue(int min, int current, int max) {
    return ((float)(current - min) / (max - min)) * 255;
}