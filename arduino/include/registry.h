#pragma once

#define REGISTRY_TEMP_CPU           0
#define REGISTRY_TEMP_GPU           1
#define REGISTRY_TEMP_MOTHERBOARD   2

#define REGISTRY_CPU_USAGE          3
#define REGISTRY_CPU_FREQUENCY      4
#define REGISTRY_CPU_FAN_SPEED      5

#define REGISTRY_GPU_USAGE          6
#define REGISTRY_GPU_FREQUENCY      7
#define REGISTRY_GPU_FAN_SPEED      8

#define REGISTRY_NUM_REGISTERS (REGISTRY_GPU_FAN_SPEED + 1)

int Registry_GetValue(int index);
int Registry_GetValue(int index, int defaultValue);
void Registry_SetValue(int index, int value);
bool Registry_IsSet(int index);