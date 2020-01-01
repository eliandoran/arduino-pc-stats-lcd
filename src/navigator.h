#pragma once

#include "loop.h"

#include "screens/idle.h"
#include "screens/temperature.h"

void (*pages[])(void) = {
    &Screen_Idle,
    &Screen_Temperature
};

int currentPageIndex;

void Navigator_Start() {
    currentPageIndex = 0;    
    Loop_SetCurrentPage(pages[currentPageIndex]);
}