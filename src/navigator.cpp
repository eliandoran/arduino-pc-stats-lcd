#include "lcd.h"
#include "loop.h"
#include "screens.h"
#include "util/trace.h"

void (*pages[])(void) = {
    &Screen_Idle,
    &Screen_Temperature
};

const int NUM_PAGES = (sizeof(pages) / sizeof(pages[0]));

int currentPageIndex;

void Navigator_SetPage(int pageIndex) {
    currentPageIndex = (pageIndex % NUM_PAGES);

    LCD_Clear();
    Loop_SetCurrentPage(pages[currentPageIndex]);
}

void Navigator_Start() {
    Navigator_SetPage(0);
}

void Navigator_GoNext() {
    TRACE("Go to next page.");
    Navigator_SetPage(currentPageIndex + 1);
}

void Navigator_GoBack() {
    TRACE("Go to the previous page.");
    Navigator_SetPage(currentPageIndex - 1);
}