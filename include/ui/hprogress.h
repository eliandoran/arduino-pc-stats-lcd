#pragma once

void HProgress_Initialize();
void HProgress_Draw(int x, int y, int width, short value);
short HProgress_GetValue(int min, int current, int max);