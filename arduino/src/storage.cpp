#include <EEPROM.h>
#include "storage.h"
#include "util/trace.h"

bool Storage_IsFormatted() {
    int magic1 = EEPROM[0];
    int magic2 = EEPROM[1];
    int magic3 = EEPROM[2];

    TRACE_VAL(String("[STORAGE] EEPROM Magic: ") + magic1 + " " + magic2 + " " + magic3)

    return (
        magic1 == STORAGE_MAGIC_1 &&
        magic2 == STORAGE_MAGIC_2 &&
        magic3 == STORAGE_MAGIC_3);
}

void Storage_Format() {
    for (uint16_t i = 0; i < EEPROM.length(); i++) {
        EEPROM.update(i, 0);
    }

    EEPROM.update(0, STORAGE_MAGIC_1);
    EEPROM.update(1, STORAGE_MAGIC_2);
    EEPROM.update(2, STORAGE_MAGIC_3);
}

void Storage_Initialize() {
    if (!Storage_IsFormatted()) {
        TRACE("[STORAGE] Requires formatting.");
        Storage_Format();
    } else {
        TRACE("[STORAGE] Is already initialized.")
    }
}

uint8_t Storage_Read(int index) {
    index += STORAGE_START_OFFSET;
    return EEPROM[index];
}

void Storage_Write(int index, uint8_t value) {
    index += STORAGE_START_OFFSET;
    EEPROM.update(index, value);
}