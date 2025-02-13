/*
 * LCD.c
 *
 * Created: 1/20/2025 9:57:50 PM
 *  Author: AbdoHamdy
 */ 

#include "LCD.h"
#include "stm32f103c6_GPIO_Driver.h"
#include "stm32f103x6.h"
#include "Utils.h"

static unsigned char counter = 0;
static enum {LCD_8_bit = 8, LCD_4_bit = 4} LCD_Interface;
static const char LCD_DataPins[] = {DB0,DB1,DB2,DB3,DB4,DB5,DB6,DB7};

static void _delay_ms(volatile uint16_t);
static void _delay_us(volatile uint16_t);
static void _delay_ns(volatile uint16_t);
/****************************************************************************************************
 * @Fn			- LCD_Init
 * @brief		- Initialize an LCD based on the required Configuration
 * @Param [in]	- LCDconfig : a pointer to a structure that contains the LCD Configuration
 * @returnValue	- None
 * @Notes		- False Configuration is handled by assigning default values
 * 				  default LCDconfig->function_set = Function_Set_8bit_2line_5x8
 * 				  default LCDconfig->Display_control = Display_Control_D_On_C_On_B_On
 * 				  default LCDconfig->Entry_mode = Entry_Mode_Inc_No_S
 */
void LCD_Init(LCD_Config_t* LCDconfig){
	int8_t i; /*iterator*/
	GPIO_PinConfig_t PinConfig; /*a structure to hold configurations of pins*/
	/*initialize directions for LCD pins*/
	/*Control pins as output*/
	PinConfig.pinMode     = GPIO_PIN_MODE_Out_PushPull;
	PinConfig.pinOutSpeed = GPIO_PIN_OUT_SPEED_10MHZ;
	/*RS*/
	PinConfig.pinNumber   = RS;
	MCAL_GPIO_Init(LCD_Control_Port, &PinConfig);
	/*RW*/
	PinConfig.pinNumber   = RW;
	MCAL_GPIO_Init(LCD_Control_Port, &PinConfig);
	/*E*/
	PinConfig.pinNumber   = E;
	MCAL_GPIO_Init(LCD_Control_Port, &PinConfig);


	/*disable LCD*/
	MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_Low);
	_delay_ms(20); /*waiting until automatic initialization finishes*/

	switch(LCDconfig->function_set){
	case Function_Set_4bit_1line_5x8  :
	case Function_Set_4bit_1line_5x10 :
	case Function_Set_4bit_2line_5x8  :
		LCD_Interface = LCD_4_bit; /*set the LCD interface*/
		/*Sets the LCD to 4-bit operation*/
		/*1. Configure LCD High pins as output*/
		for(i = LCD_TotDataPins - 1; i >= LCD_TotDataPins - LCD_Interface;i--){
			PinConfig.pinNumber   = LCD_DataPins[i];
			MCAL_GPIO_Init(LCD_Data_Port, &PinConfig);
		}
		/*2. then send the command*/
		for(i = LCD_TotDataPins - 1; i >= LCD_TotDataPins - LCD_Interface;i--){
			MCAL_GPIO_WritePin(LCD_Data_Port, LCD_DataPins[i], (LCDconfig->function_set >> i) &1);
		}

		MCAL_GPIO_WritePin(LCD_Control_Port, RS, GPIO_PIN_Value_Low);/*Instruction*/
		MCAL_GPIO_WritePin(LCD_Control_Port, RW, GPIO_PIN_Value_Low);/*Write*/

		_delay_ns(40); /*TAS = 50ns (min= 40ns)*/
		MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_High);/*Enable the LCD*/
		_delay_ns(300); /*TCYCE / 2 = 300ns (min = 250ns)*/
		MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_Low);/*disable the LCD*/
		_delay_ns(300); /*TCYCE/2 = 300ns (min = 250ns)*/
		/*only this instruction completes with one write.*/
		break;
	case Function_Set_8bit_1line_5x8 :
	case Function_Set_8bit_1line_5x10:
	case Function_Set_8bit_2line_5x8 :
		LCD_Interface = LCD_8_bit;
		break;
	default:
		LCD_Interface = LCD_8_bit;
		LCDconfig->function_set = Function_Set_8bit_2line_5x8;
		break;
	}
	switch (LCDconfig->Display_control) {
	case Display_Control_D_Off:
	case Display_Control_D_On:
	case Display_Control_D_On_C_On:
	case Display_Control_D_On_B_On:
	case Display_Control_D_On_C_On_B_On:
		/*Correct Initialization*/
		/*do nothing*/
		break;
	default:
		/*false initialization*/
		LCDconfig->Display_control = Display_Control_D_On_C_On_B_On;
		break;
	}

	switch (LCDconfig->Entry_mode) {
	case Entry_Mode_Inc_No_S:
	case Entry_Mode_Inc_With_S:
	case Entry_Mode_Dec_No_S:
	case Entry_Mode_Dec_With_S:
		/*Correct Initialization*/
		/*do nothing*/
		break;
	default:
		/*false initialization*/
		LCDconfig->Entry_mode = Entry_Mode_Inc_No_S;
		break;
	}
	/*after the LCD is ready Start Sending the Commands*/
	LCD_Write_Command(LCDconfig->function_set);
	LCD_Write_Command(LCDconfig->Entry_mode);
	LCD_Write_Command(LCDconfig->Display_control);
	LCD_Write_Command(LCD_Clear);
	LCD_Write_Command(LCD_Return_Home);
}
/****************************************************************************************************
 * @Fn			- LCD_Write_Data
 * @brief		- Write a String on the LCD
 * @Param [in]	- input : a pointer to the first character in the string to be written
 * @returnValue	- None
 * @Notes		- None
 */
void LCD_Write_Data(char* input){
	while(*input){
		LCD_SendCharacter(*(input++));
	}
}
/****************************************************************************************************
 * @Fn			- LCD_Write_Command
 * @brief		- Send Command To the LCD
 * @Param [in]	- command : the command to be sent
 * @returnValue	- None
 * @Notes		- Wrong or Invalid Command is not handled
 */
void LCD_Write_Command(char command){
	int8_t i; /*iterator*/
	GPIO_PinConfig_t pinConfig; /*a structure to hold configurations of pins*/

	/*Change direction of data bins to be output*/
	pinConfig.pinMode     = GPIO_PIN_MODE_Out_PushPull;
	pinConfig.pinOutSpeed = GPIO_PIN_OUT_SPEED_10MHZ;
	for(i = LCD_TotDataPins - 1; i >= LCD_TotDataPins - LCD_Interface;i--){
		pinConfig.pinNumber   = LCD_DataPins[i];
		MCAL_GPIO_Init(LCD_Data_Port, &pinConfig);
	}

	MCAL_GPIO_WritePin(LCD_Control_Port, RS, GPIO_PIN_Value_Low);/*Instruction*/
	MCAL_GPIO_WritePin(LCD_Control_Port, RW, GPIO_PIN_Value_Low);/*Write*/

	/*Write command*/
	for(i = LCD_TotDataPins - 1; i >= LCD_TotDataPins - LCD_Interface;i--){
		MCAL_GPIO_WritePin(LCD_Data_Port, LCD_DataPins[i], (command >> i) &1);
	}
	if(LCD_Interface == LCD_4_bit){
		_delay_ns(50); /*TAS = 50ns (min = 40ns)*/
		MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_High);/*Enable the LCD*/
		_delay_ns(300); /*TCYCE / 2 = 300ns (min = 250ns)*/
		MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_Low);/*disable the LCD*/
		_delay_ns(20); /*TH = 20ns (min = 10ns)*/
		/*send lower nibble*/
		for(i = LCD_TotDataPins - 1; i >= LCD_TotDataPins - LCD_Interface;i--){
			MCAL_GPIO_WritePin(LCD_Data_Port, LCD_DataPins[i], (command >> i % LCD_Interface) &1);
		}
		_delay_ns(300); /*TCYCE/2 = 300ns (min = 250ns)*/
	}

	_delay_ns(50); /*TAS = 50ns (min = 40ns)*/
	MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_High);/*Enable the LCD*/
	_delay_ns(300); /*TCYCE / 2 = 300ns (min = 250ns)*/
	MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_Low);/*disable the LCD*/
	_delay_ns(300); /*TCYCE/2 = 300ns (min = 250ns)*/
	_delay_ms(2); /*wait 2ms before performing any other command*/

	/*update the counter if the command was change cursor position*/
	if(command >= F00){
		if(command < S00){
			counter = command - 0xF00;
		}else{
			counter = 17 + (command - S00);
		}
	}else if(command == LCD_Return_Home){
		counter = 0;
	}
}
/****************************************************************************************************
 * @Fn			- LCD_SendCharacter
 * @brief		- Send a character to be displayed on the LCD
 * @Param [in]	- c : the character to be displayed
 * @returnValue	- None
 * @Notes		- None
 */
void LCD_SendCharacter(char c){
	int8_t i; /*iterator*/
	GPIO_PinConfig_t pinConfig; /*a structure to hold configurations of pins*/

	if(counter++ == LCD_Line_Length){ /*first line filled*/
		DDRAM_Address = S00;
		LCD_Write_Command(DDRAM_Address);
	}else if(counter > LCD_Line_Length * 2){ /*both lines are filled*/
		/*Clear Screen*/
		LCD_Write_Command(LCD_Clear);
		LCD_Write_Command(LCD_Return_Home);
		counter = 0;
	}
	/*Change direction of data bins to be output*/
	pinConfig.pinMode     = GPIO_PIN_MODE_Out_PushPull;
	pinConfig.pinOutSpeed = GPIO_PIN_OUT_SPEED_10MHZ;
	for(i = LCD_TotDataPins - 1; i >= LCD_TotDataPins - LCD_Interface;i--){
		pinConfig.pinNumber   = LCD_DataPins[i];
		MCAL_GPIO_Init(LCD_Data_Port, &pinConfig);
	}

	MCAL_GPIO_WritePin(LCD_Control_Port, RS, GPIO_PIN_Value_High);/*data*/
	MCAL_GPIO_WritePin(LCD_Control_Port, RW, GPIO_PIN_Value_Low);/*Write*/

	/*write the character*/
	for(i = LCD_TotDataPins - 1; i >= LCD_TotDataPins - LCD_Interface;i--){
		MCAL_GPIO_WritePin(LCD_Data_Port, LCD_DataPins[i], (c >> i) &1);
	}
	if(LCD_Interface == LCD_4_bit){
		_delay_ns(50); /*TAS = 50ns (min = 40ns)*/
		MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_High);/*Enable the LCD*/
		_delay_ns(300); /*TCYCE / 2 = 300ns (min = 250ns)*/
		MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_Low);/*disable the LCD*/
		_delay_ns(20); /*TH = 20ns (min = 10ns)*/
		/*send lower nibble*/
		for(i = LCD_TotDataPins - 1; i >= LCD_TotDataPins - LCD_Interface;i--){
			MCAL_GPIO_WritePin(LCD_Data_Port, LCD_DataPins[i], (c >> i % LCD_Interface) &1);
		}
		_delay_ns(300); /*TCYCE/2 = 300ns (min = 250ns)*/
	}

	_delay_ns(50); /*TAS = 50ns (min = 40ns)*/
	MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_High);/*Enable the LCD*/
	_delay_ns(300); /*TCYCE / 2 = 300ns (min = 250ns)*/
	MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_Low);/*disable the LCD*/
	_delay_ns(300); /*TCYCE/2 = 300ns (min = 250ns)*/
}
/****************************************************************************************************
 * @Fn			- LCD_Busy
 * @brief		- Check either the LCD is Busy or not
 * @returnValue	- LCD Busy Status
 * 				  Either true "busy" or false "Not Busy"
 * @Notes		- None
 */
boolean LCD_Busy(void){
	boolean busy = false; /*busy flag*/
	int8_t i; /*iterator*/
	GPIO_PinConfig_t pinConfig; /*a structure to hold pins configurations*/

	/*Change direction of data bins to be input*/
	pinConfig.pinMode = GPIO_PIN_MODE_IN_PullDown;
	for(i = LCD_TotDataPins - 1; i >= LCD_TotDataPins - LCD_Interface;i--){
		pinConfig.pinNumber   = LCD_DataPins[i];
		MCAL_GPIO_Init(LCD_Data_Port, &pinConfig);
	}

	MCAL_GPIO_WritePin(LCD_Control_Port, RS, GPIO_PIN_Value_Low);/*Instruction*/
	MCAL_GPIO_WritePin(LCD_Control_Port, RW, GPIO_PIN_Value_High);/*read*/


	_delay_ns(50); /*TAS = 50ns (min = 40ns)*/
	MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_High); /*Enable the LCD*/
	_delay_ns(200); /*tDDR (wait until data is ready) = 200ns (min = 160ns)*/
	busy = MCAL_GPIO_ReadPin(LCD_Data_Port, DB7); /*read busy flag*/
	_delay_ns(200); /*TCYCE / 2 = 200 + 200 = 400ns (min = 250ns)*/
	MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_Low); /*Disable the LCD*/
	_delay_ns(400); /*TCYCE/2 = 400ns (min = 250ns)*/
	/*Simulate reading the remaining address*/
	if(LCD_Interface == LCD_4_bit){
		/*read the lower nibble of the address*/
		MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_High); /*Enable the LCD*/
		_delay_ns(200); /*tDDR (wait until data is ready) = 200ns (min = 160ns)*/
		/*****read lower nibble here*****/
		_delay_ns(200); /*TCYCE / 2 = 200 + 200 = 400ns (min = 250ns)*/
		MCAL_GPIO_WritePin(LCD_Control_Port, E, GPIO_PIN_Value_Low); /*Disable the LCD*/
		_delay_ns(400); /*TCYCE/2 = 400ns (min = 250ns)*/
	}
	return busy;
}
/****************************************************************************************************
 * @Fn			- _delay_ms
 * @brief		- Software delay
 * @returnValue	- None
 * @Notes		- a private function used for LCD.c only
 */
static void _delay_ms( uint16_t time){
	while(time--){
		uint32_t i ;
		for(i = 0 ; i < 1000; i++);
	}
}
/****************************************************************************************************
 * @Fn			- _delay_us
 * @brief		- Software delay
 * @returnValue	- None
 * @Notes		- a private function used for LCD.c only
 */
static void _delay_us( uint16_t time){
	while(time--){
		uint16_t i ;
		for(i = 0 ; i < 500; i++);
	}
}
/****************************************************************************************************
 * @Fn			- _delay_ns
 * @brief		- Software delay
 * @returnValue	- None
 * @Notes		- a private function used for LCD.c only
 */
static void _delay_ns( uint16_t time){
	while(time--);
}
