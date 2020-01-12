#pragma once

#ifndef CONFIG_H
#define CONFIG_H

#define SERIAL_BAUDRATE 345600

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

#define LCD_CHAR_WIDTH 5
#define LCD_CHAR_HEIGHT 8

/*
 * Time format
 */
#define TIME_SEPARATOR ':'

#endif