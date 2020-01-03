#pragma once

void Loop_SetInterval(int interval);
void Loop_SetCurrentPage(void (*page)(bool));
void Loop_ResetInterval();
void Loop_Invalidate();
void Loop_Enter();