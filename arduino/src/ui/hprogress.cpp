#include "ui/characters.h"
#include "lcd.h"
#include "util/trace.h"

#define INDEX_HPROGRESS_20  7
#define INDEX_HPROGRESS_40  6
#define INDEX_HPROGRESS_60  5
#define INDEX_HPROGRESS_80  4
#define INDEX_HPROGRESS_100 3

const byte HPROGRESS_INTERMEDIATE_STEPS[] = {
    INDEX_HPROGRESS_80,
    INDEX_HPROGRESS_60,
    INDEX_HPROGRESS_40,
    INDEX_HPROGRESS_20
};

const byte HPROGRESS_NUM_INTERMEDIATE_STEPS = (sizeof(HPROGRESS_INTERMEDIATE_STEPS) / sizeof(HPROGRESS_INTERMEDIATE_STEPS[0]));

void HProgress_Initialize() {
    LCD_SetCustomCharacter(INDEX_HPROGRESS_20,  CHAR_HPROGRESS_20);
    LCD_SetCustomCharacter(INDEX_HPROGRESS_40,  CHAR_HPROGRESS_40);
    LCD_SetCustomCharacter(INDEX_HPROGRESS_60,  CHAR_HPROGRESS_60);
    LCD_SetCustomCharacter(INDEX_HPROGRESS_80,  CHAR_HPROGRESS_80);
    LCD_SetCustomCharacter(INDEX_HPROGRESS_100, CHAR_HPROGRESS_100);
}

void HProgress_Draw(int x, int y, int width, short value) {
    int numPixels = (((float)value / 100) * width * LCD_CHAR_WIDTH);
    int startX = x;
    
    // Draw full segments
    int numFullSegments = (numPixels / LCD_CHAR_WIDTH);
    for (int i=0; i<numFullSegments; i++) {
        LCD_DrawCustomCharacter(INDEX_HPROGRESS_100, x, y);
        x++;
    }

    // Draw last partial segment.
    int numPartialSegments = (numPixels % LCD_CHAR_WIDTH);
    if (numPartialSegments > 0) {
        int index = ((HPROGRESS_NUM_INTERMEDIATE_STEPS - 1) - (numPartialSegments - 1));
        LCD_DrawCustomCharacter(HPROGRESS_INTERMEDIATE_STEPS[index], x, y);
        x++;
    }

    // Fill the remainder with empty space (to clean up previous values).
    int emptySegments = (width - (x - startX));
    LCD_ClearLine(x, y, emptySegments);
}

short HProgress_GetValue(int min, int current, int max) {
    return ((float)(current - min) / (max - min)) * 100;
}