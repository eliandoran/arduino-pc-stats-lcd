#pragma once

#define REGISTRY_NUM_REGISTERS 255

#define REGISTRY_TEMP_CPU           0
#define REGISTRY_TEMP_GPU           1
#define REGISTRY_TEMP_MOTHERBOARD   2

int Registry_GetValue(int index);
void Registry_SetValue(int index, int value);
bool Registry_IsSet(int index);