#include "registry.h"

int REGISTRY[REGISTRY_NUM_REGISTERS];

int Registry_GetValue(int index) {
    if (index < 0 || index >= REGISTRY_NUM_REGISTERS)
        return -1;

    return REGISTRY[index];
}

void Registry_SetValue(int index, int value) {
    if (index < 0 || index >= REGISTRY_NUM_REGISTERS)
        return;

    REGISTRY[index] = value;
}