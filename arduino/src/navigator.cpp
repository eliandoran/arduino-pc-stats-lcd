#include "lcd.h"
#include "loop.h"
#include "screens.h"
#include "storage.h"
#include "util/trace.h"
#include "navigator.h"

void (*pages[])(bool) = {
    &Screen_Idle,
    &Screen_Temperature,
    &Screen_CPU_GPU_Usage,
    &Screen_CPU_Details,
    &Screen_GPU_Details
};

const int NUM_PAGES = (sizeof(pages) / sizeof(pages[0]));

int currentPageIndex;

void Navigator_Start() {
    int lastPage = Storage_Read(STORAGE_LAST_PAGE);
    Navigator_SetPage(lastPage);
}

void Navigator_GoNext() {
    TRACE("[NAVIGATOR] Go to next page.");
    Navigator_SetPage((currentPageIndex + 1) % NUM_PAGES);
}

void Navigator_GoBack() {
    TRACE("[NAVIGATOR] Go to the previous page.");
    Navigator_SetPage((currentPageIndex - 1 + NUM_PAGES) % NUM_PAGES);
}

void Navigator_SetPage(int pageIndex) {
    currentPageIndex = abs(pageIndex % NUM_PAGES);
    TRACE_VAL(String("[NAVIGATOR] Set page index: ") + currentPageIndex);   

    LCD_Clear();
    Loop_SetCurrentPage(pages[currentPageIndex]);
    Storage_Write(STORAGE_LAST_PAGE, currentPageIndex);
}