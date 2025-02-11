/*
 * LCD.h
 *
 * Created: 1/20/2025 9:12:13 PM
 *  Author: AbdoHamdy
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "GPIO.h"
#include "Utils.h"
#define LCD_Line_Length       16
/*define LCD Pins Mapping*/
#define LCD_Control_Port      PORTB
#define LCD_Control_Direction DDRB
#define RS  PB1
#define RW  PB2
#define E   PB3

#define LCD_Data_Port      PORTA
#define LCD_Data_PinVal    PINA
#define LCD_Data_Direction DDRA
#define DB0  PA0
#define DB1  PA1
#define DB2  PA2
#define DB3  PA3
#define DB4  PA4
#define DB5  PA5
#define DB6  PA6
#define DB7  PA7

/*define LCD Configurations and commands*/
enum {F00 = 0x80,F01,F02,F03,F04,F05,F06,F07,F08,F09,F10,F11,F12,F13,F14,F15,
S00 = 0xC0,S01,S02,S03,S04,S05,S06,S07,S08,S09,S10,S11,S12,S13,S14,S15 } DDRAM_Address;

enum {Increment_No_Shift = 0x06, Increment_With_Shift = 0x07, Dncrement_No_Shift = 0x04, Decrement_With_Shift = 0x05} entryMode;
enum {Display_off = 0x8, Display_on = 0xC,Cursor_on = 0xA,Blinking = 0x9}Display_Control;
enum {Cursor_Shift_Left = 0x10,  Cursor_Shift_right = 0x14, Display_Shift_Left = 0x18, Display_Shift_Right = 0x1C} Shift_Function;
enum {
	four_bit_1line_5x8  = 0x20,
	four_bit_1line_5x10 = 0x24,
	four_bit_2line_5x8  = 0x28,
	eight_bit_1line_5x8 = 0x30,
	eight_bit_1line_5x10= 0x34,
	eight_bit_2line_5x8 = 0x38
} Function_Set;

#define LCD_Clear  0x01
#define LCD_Return_Home 0x02


void LCD_Init(void);
void LCD_Write_Data(char*);
void LCD_Write_Command(char);
void LCD_SendCharacter(char);
boolean LCD_Busy(void);

#endif /* LCD_H_ */