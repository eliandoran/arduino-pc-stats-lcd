#pragma once

void Loop_SetInterval(int interval);
void Loop_SetCurrentPage(void (*page)(void));
void Loop_ResetInterval();
void Loop_Enter();