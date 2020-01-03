#include "registry.h"

int REGISTRY[REGISTRY_NUM_REGISTERS];
bool REGISTRY_MAP[REGISTRY_NUM_REGISTERS]; // true indicates that the corresponding index has a value assigned to it.

int Registry_GetValue(int index) {
    return Registry_GetValue(index, 0);
}

int Registry_GetValue(int index, int defaultValue) {
    if (index < 0 || index >= REGISTRY_NUM_REGISTERS)
        return -1;

    if (!Registry_IsSet(index))
        return defaultValue;

    return REGISTRY[index];
}

void Registry_SetValue(int index, int value) {
    if (index < 0 || index >= REGISTRY_NUM_REGISTERS)
        return;

    REGISTRY[index] = value;
    REGISTRY_MAP[index] = true;
}

bool Registry_IsSet(int index) {
    return REGISTRY_MAP[index];
}