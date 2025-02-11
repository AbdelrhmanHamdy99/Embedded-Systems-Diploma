/*
 * stm32f103c6_GPIO_Driver.h
 *
 *  Created on: Feb 4, 2025
 *      Author: AbdoHamdy
 */

#ifndef INC_STM32F103C6_GPIO_DRIVER_H_
#define INC_STM32F103C6_GPIO_DRIVER_H_
/******************************************************************
							Includes
******************************************************************/
#include "stm32f103x6.h"
/*================================================================================================================*/
/******************************************************************
				User type definitions (structures)
******************************************************************/
typedef struct {
	uint8_t pinNumber	; /*Specifies GPIO Pin to be configurew
							Can be a value of @ref GPIO_PIN_define*/
	uint8_t pinMode   	; /*Specifies the operating mode for the selected pin
							can be a value of @ref GPIO_PIN_MODE_define*/
	uint8_t pinOutSpeed	; /*Specifies the speed of the selected output pin
							can be a value of @ref GPIO_PIN_OUT_SPEED_define*/
} GPIO_PinConfig_t;
/*================================================================================================================*/
/******************************************************************
				Macros Configuration References
******************************************************************/
/*@ref GPIO_PIN_define*/
#define GPIO_PIN_0      				0
#define GPIO_PIN_1      				1
#define GPIO_PIN_2      				2
#define GPIO_PIN_3      				3
#define GPIO_PIN_4      				4
#define GPIO_PIN_5      				5
#define GPIO_PIN_6      				6
#define GPIO_PIN_7      				7
#define GPIO_PIN_8      				8
#define GPIO_PIN_9      				9
#define GPIO_PIN_10     				10
#define GPIO_PIN_11     				11
#define GPIO_PIN_12     				12
#define GPIO_PIN_13     				13
#define GPIO_PIN_14     				14
#define GPIO_PIN_15     			  	15

/*@ref GPIO_PIN_MODE_define*/
#define GPIO_PIN_MODE_Out_PushPull     	0
#define GPIO_PIN_MODE_Out_OpenDrain    	1
#define GPIO_PIN_MODE_AF_Out_PushPull  	2
#define GPIO_PIN_MODE_AF_Out_OpenDrain 	3
#define GPIO_PIN_MODE_IN_Analog        	4
#define GPIO_PIN_MODE_IN_Floating      	5
#define GPIO_PIN_MODE_IN_PullDown      	6
#define GPIO_PIN_MODE_IN_PullUp        	7

/*@ref GPIO_PIN_OUT_SPEED_define*/
#define GPIO_PIN_OUT_SPEED_10MHZ		1
#define GPIO_PIN_OUT_SPEED_2MHZ			2
#define GPIO_PIN_OUT_SPEED_50MHZ		3

/*@ref GPIO_PIN_Value_define */
#define GPIO_PIN_Value_High             1
#define GPIO_PIN_Value_Low              0
/*================================================================================================================*/
/******************************************************************
				APIs Supported by "MCAL GPIO DRIVER"
******************************************************************/
void 		MCAL_GPIO_Init(GPIO_T* , GPIO_PinConfig_t*);
void 		MCAL_GPIO_DeInit(GPIO_T*);
uint8_t 	MCAL_GPIO_ReadPin(GPIO_T*,uint8_t);
uint16_t 	MCAL_GPIO_ReadPort(GPIO_T*);
void 		MCAL_GPIO_WritePin(GPIO_T*, uint8_t,uint8_t);
void 		MCAL_GPIO_WritePort(GPIO_T*, uint16_t);
void 		MCAL_GPIO_TogglePin(GPIO_T*,uint8_t);
void 		MCAL_GPIO_TogglePort(GPIO_T*);
void 		MCAL_GPIO_LockPin(GPIO_T*,uint8_t);


#endif /* INC_STM32F103C6_GPIO_DRIVER_H_ */
