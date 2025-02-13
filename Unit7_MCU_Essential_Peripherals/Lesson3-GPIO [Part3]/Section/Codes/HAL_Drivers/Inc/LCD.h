/*
 * LCD.h
 *
 * Created: 1/20/2025 9:12:13 PM
 *  Author: AbdoHamdy
 */ 


#ifndef LCD_H_
#define LCD_H_
/******************************************************************
							Includes
******************************************************************/
#include "stm32f103c6_GPIO_Driver.h"
#include "stm32f103x6.h"
#include "Utils.h"
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
#define LCD_Control_Port	GPIOA
#define RS  				GPIO_PIN_10
#define RW  				GPIO_PIN_9
#define E   				GPIO_PIN_8

#define LCD_Data_Port      	GPIOB
#define DB0  				GPIO_PIN_6
#define DB1  				GPIO_PIN_5
#define DB2  				GPIO_PIN_4
#define DB3  				GPIO_PIN_3
#define DB4  				GPIO_PIN_15
#define DB5  				GPIO_PIN_14
#define DB6  				GPIO_PIN_13
#define DB7  				GPIO_PIN_12

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
void LCD_Init(LCD_Config_t*);
void LCD_Write_Data(char*);
void LCD_Write_Command(char);
void LCD_SendCharacter(char);
boolean LCD_Busy(void);
void clock_Init(void);

#endif /* LCD_H_ */
