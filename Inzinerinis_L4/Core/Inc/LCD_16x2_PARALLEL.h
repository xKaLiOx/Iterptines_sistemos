/*
 * LCD_16x2_PARALLEL.h
 *
 *  Created on: Mar 30, 2025
 *      Author: Linas
 */

#ifndef INC_LCD_16X2_PARALLEL_H_
#define INC_LCD_16X2_PARALLEL_H_

#define LCD_ROWS 2
#define LCD_COLS 16

#define LCD_RS_DATA 1
#define LCD_RS_INSTRUCTION 0

#define LCD_DISPLAY_CLEAR 0x01 // CLEAR DDRAM AND START FROM 0
#define LCD_RETURN_HOME 0x02
#define LCD_Entry_MODE 0x04 // | x0 I/D 1 to right, DDRAM+ / x SHIFT 0 NO 1 SHIFT to I/D
#define LCD_SET_DISPLAY_DEFAULT 0x0C // 1/DISPLAY/CURSOR/BLINKING C
#define LCD_DISPLAY_OFF 0x8 // turn off display
#define LCD_SHIFT_C_AND_DIRECTION 0x10 //0x8xx00 S/C 0(CURSOR) 1(ALL DISPLAY) R/L 0 LEFT 1 RIGHT
#define LCD_FUNCTION_SET 0x20 // DL 4 bit 0 / N 1-2 line / F type 5x8 5x11
#define LCD_CGRAM_ADRESS 0x40 // AC0-AC5 adresas
#define LCD_DDRAM_ADRESS 0x80 //AC0-AC6 adresas

/*
 * LCD_16x2_PARALLEL.c
 *
 *  Created on: Mar 30, 2025
 *      Author: Linas
 */

#include "main.h"
#include "stm32l4xx_hal.h"

extern void SEND_4_BIT(char data, int rsPin);
extern void LCD_SEND_COMMAND(char komanda);
extern void LCD_SEND_DATA(char komanda);
extern void LCD_CLEAR();
extern void LCD_CLEAR_DRAM();
extern void LCD_Init();
extern void LCD_SEND_STR(const char data[], unsigned int place, unsigned int level);

#endif /* INC_LCD_16X2_PARALLEL_H_ */
