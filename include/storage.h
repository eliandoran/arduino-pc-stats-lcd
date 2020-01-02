#pragma once

#include <stdint.h>

#define STORAGE_MAGIC_1 0xC0
#define STORAGE_MAGIC_2 0x0F
#define STORAGE_MAGIC_3 0xEE

#define STORAGE_START_OFFSET 3

#define STORAGE_LAST_PAGE 0

void Storage_Initialize();
uint8_t Storage_Read(int index);
void Storage_Write(int index, uint8_t value);