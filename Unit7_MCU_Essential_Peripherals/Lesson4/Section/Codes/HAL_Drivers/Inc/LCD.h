/*
 * LCD.h
 *
 * Created: 2/23/2025 1:05:01 PM
 *  Author: AbdoHamdy
 */ 


#ifndef LCD_H_
#define LCD_H_

/******************************************************************
							Includes
******************************************************************/
#include "Atmega32_DIO.h"
#include "Atmega32.h"
#include "Utils.h"
#include <stdint.h>
/*================================================================================================================*/
/*****************************************************************
 * 						LCD Parameters							 *
******************************************************************/
#define LCD_Line_Length		16
#define LCD_TotDataPins		8

enum {F00 = 0x80,F01,F02,F03,F04,F05,F06,F07,F08,F09,F10,F11,F12,F13,F14,F15,
S00 = 0xC0,S01,S02,S03,S04,S05,S06,S07,S08,S09,S10,S11,S12,S13,S14,S15 } DDRAM_Address;

/*****************************************************************
 * 					   LCD Pins Mapping							 *
******************************************************************/
#define LCD_Control_Port	DIOB
#define RS  				DIO_Pin_1
#define RW  				DIO_Pin_2
#define E   				DIO_Pin_3

#define LCD_Data_Port      	DIOA
#define DB0  				DIO_Pin_Not_Used
#define DB1  				DIO_Pin_Not_Used
#define DB2  				DIO_Pin_Not_Used
#define DB3  				DIO_Pin_Not_Used
#define DB4  				DIO_Pin_4
#define DB5  				DIO_Pin_5
#define DB6  				DIO_Pin_6
#define DB7  				DIO_Pin_7

/*****************************************************************
 * 			LCD User Configurations and commands				*
******************************************************************/
typedef struct {
	uint8_t function_set;    /*can be a value of @ref Function_Set_defined*/
	uint8_t Display_control; /*can be a value of @ref Display_Control_defined*/
	uint8_t Entry_mode;		 /*can be a value of @ref Entry_Mode_defined*/
}LCD_Config_t;


#define LCD_Clear  0x01
#define LCD_Return_Home 0x02

enum {Cursor_Shift_Left = 0x10,  Cursor_Shift_right = 0x14, Display_Shift_Left = 0x18, Display_Shift_Right = 0x1C} Shift_Function;

/*****************************************************************
 * 				Macros Configuration References					*
******************************************************************/
/*@ref Function_Set_defined*/
#define Function_Set_4bit_1line_5x8   	0x20
#define Function_Set_4bit_1line_5x10  	0x24
#define Function_Set_4bit_2line_5x8   	0x28
#define Function_Set_8bit_1line_5x8   	0x30
#define Function_Set_8bit_1line_5x10  	0x34
#define Function_Set_8bit_2line_5x8   	0x38

/*@ref Display_Control_defined*/
#define Display_Control_D_Off           0x8 /*Display Off*/
#define Display_Control_D_On            0xC /*Display on , Cursor off, Blinking off*/
#define Display_Control_D_On_C_On       0xE /*Display on , Cursor on , Blinking off*/
#define Display_Control_D_On_B_On       0xD /*Display on , Cursor off, Blinking on */
#define Display_Control_D_On_C_On_B_On  0xF /*Display on , Cursor on, Blinking on*/

/*@ref Entry_Mode_defined */
#define Entry_Mode_Inc_No_S				0x06 /*Increment no   shift*/
#define Entry_Mode_Inc_With_S			0x07 /*Increment With shift*/
#define Entry_Mode_Dec_No_S				0x04 /*Decrement no   shift*/
#define Entry_Mode_Dec_With_S			0x05 /*Decrement with shift*/

/******************************************************************
				APIs Supported by "HAL LCD DRIVER"
******************************************************************/
void	LCD_Init			(LCD_Config_t*);
void	LCD_Write_Data		(char*);
void	LCD_Write_Command	(char);
void	LCD_SendCharacter	(char);
uint8_t LCD_Busy			(void);
void	clock_Init			(void);

#endif /* LCD_H_ */