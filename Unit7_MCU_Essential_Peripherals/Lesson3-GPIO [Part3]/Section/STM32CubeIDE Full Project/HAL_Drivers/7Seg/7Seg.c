
#include "7Seg.h"
#include "stm32f103c6_GPIO_Driver.h"
#include "stm32f103x6.h"
static const char SevenSegPins[] = {SevenSeg_a, SevenSeg_b, SevenSeg_c, SevenSeg_d, SevenSeg_e, SevenSeg_f, SevenSeg_g};
static enum {Com_An = SevenSeg_Type_Com_An, Com_Cath = SevenSeg_Type_Com_Cath}SevenSeg_Type;
/*
 * @Fn			- SevenSeg_Init
 * @brief		- Initializes 7Seg by setting all pins as output
 * @Param [in]	- type : define either the 7Seg is common anode or common cathode
 * 				  Can be a value of @ref SevenSeg_Type_defined
 * @returnValue	- None
 * @Notes		- if invalid argument is passed the 7Seg will be considered as common anode
 */
void SevenSeg_Init(uint8_t type){
	uint8_t i; /*iterator*/
	GPIO_PinConfig_t pinConfig; /*a structure to hold pins configurations*/
	/*configure 7Seg pins as output*/
	pinConfig.pinMode     = GPIO_PIN_MODE_Out_PushPull;
	pinConfig.pinOutSpeed = GPIO_PIN_OUT_SPEED_10MHZ;
	for(i = 0; i < SevenSeg_nPins; i++){
		pinConfig.pinNumber = SevenSegPins[i];
		MCAL_GPIO_Init(SevenSegPort, &pinConfig);
	}
	SevenSeg_Type = type == SevenSeg_Type_Com_Cath ? Com_Cath : Com_An;
	SevenSeg_Clear();
}
/*
 * @Fn			- SevenSeg_DisplayNumber
 * @brief		- display a number on the 7Seg
 * @Param [in]	- num : the number to be displayed
 * @returnValue	- None
 * @Notes		- invalid parameter is handled by clearing the 7Seg
 * 				  this function can handle numbers in numeric or ascii value
 */
void SevenSeg_DisplayNumber(char num){
	uint8_t i; /*iterator*/
	uint8_t pinVal = SevenSeg_Type == Com_Cath ? GPIO_PIN_Value_High : GPIO_PIN_Value_Low;
	/*the most common pattern is 0b1111011*/
	/*start by default value*/
	for(i = 0 ; i < SevenSeg_nPins;i++){
		MCAL_GPIO_WritePin(SevenSegPort, SevenSegPins[i], pinVal);
	}
	MCAL_GPIO_WritePin(SevenSegPort, SevenSeg_e, !pinVal);

	/*toggle pins based on the number to be displayed*/
	switch (num) {
	case 0:
	case '0':
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_e);
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_g);
		break;
	case 1:
	case '1':
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_a);
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_d);
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_f);
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_g);
		break;
	case 2:
	case '2':
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_c);
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_e);
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_f);
		break;
	case 3:
	case '3':
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_f);
		break;
	case 4:
	case '4':
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_a);
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_d);
		break;
	case 5:
	case '5':
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_b);
		break;
	case 6:
	case '6':
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_b);
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_e);
		break;
	case 7:
	case '7':
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_d);
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_f);
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_g);
		break;
	case 8:
	case '8':
		MCAL_GPIO_TogglePin(SevenSegPort, SevenSeg_e);
		break;
	case 9:
	case '9':
		/*nothing to toggle*/
		break;
	default:
		/*wrong entry*/
		/*Clear the 7Seg Display*/
		SevenSeg_Clear();
		break;
	}
}
/*
 * @Fn			- SevenSeg_Clear
 * @brief		- Clears the 7Seg Display
 * @returnValue	- None
 * @Notes		- None
 */
void SevenSeg_Clear(void){
	uint8_t i; /*iterator*/
	uint8_t resetVal = SevenSeg_Type == Com_Cath ? GPIO_PIN_Value_Low : GPIO_PIN_Value_High;
	/*reset all pins*/
	for(i = 0 ; i < SevenSeg_nPins;i++){
		MCAL_GPIO_WritePin(SevenSegPort, SevenSegPins[i], resetVal);
	}
}
