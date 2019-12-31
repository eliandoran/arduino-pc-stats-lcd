#pragma once

#define SERIAL_BAUDRATE 9600

/*
 * Real Time Clock
 */
#define RTC_MINIMAL_TIMESTAMP DateTime(F(__DATE__), F(__TIME__))

/*
 * LCD Display
 */
#define LCD_ADDRESS 0x3F
#define LCD_COLUMNS 16
#define LCD_ROWS 2