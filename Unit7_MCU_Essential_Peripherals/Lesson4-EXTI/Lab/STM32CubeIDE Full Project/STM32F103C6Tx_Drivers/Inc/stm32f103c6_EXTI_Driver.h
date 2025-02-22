/*
 * stm32f103c6_EXTI_Driver.h
 *
 *  Created on: Feb 20, 2025
 *      Author: AbdoHamdy
 */

#ifndef INC_STM32F103C6_EXTI_DRIVER_H_
#define INC_STM32F103C6_EXTI_DRIVER_H_

/*****************************************************************
 * 							Includes							*
 ******************************************************************/
#include "stm32f103x6.h"
#include "stm32f103c6_GPIO_Driver.h"
#include <stdint.h>
/******************************************************************
				User type definitions (structures)
 ******************************************************************/
typedef struct {
	GPIO_T* GPIOx			; /*The Port number that EXTIn will map to
		 	 	 	 	 	 	Can be a value of "GPIO Instants"*/
	uint8_t pinNumber		; /*Specifies GPIO Pin from which interrupt will arrive
								Can be a value of @ref GPIO_PIN_define*/
	uint8_t EXTI_Line		; /*Specifies the Line number of the Interrupt
	 	 	 	 	 	 	 	Can be a value of @ref EXTI_Line_defined*/
}EXTI_PinMapping_t;
typedef struct {
	EXTI_PinMapping_t   pinMapping		 ; /*Specifies the pin Mapping for an interrupt*/
	uint8_t 		  	trigerringEdge	 ; /*Specifies when to fire an interrupt
	 	 	 	 	 	 	 				Can be a value of @ref EXTI_Trigger_defined*/
	uint8_t 			interruptStatus	 ; /*Specifies whether to enable or disable an interrupt
											Can be a value of @ref EXTI_Status_defined*/
	void 				(*callback)(void); /*A pointer to the callback function*/
}EXTI_Config_t;

/*****************************************************************
 * 				Macros Configuration References					*
 ******************************************************************/
/*EXTI_Line_defined*/
#define EXTI_Line_0						0
#define EXTI_Line_1						1
#define EXTI_Line_2						2
#define EXTI_Line_3						3
#define EXTI_Line_4						4
#define EXTI_Line_5						5
#define EXTI_Line_6						6
#define EXTI_Line_7						7
#define EXTI_Line_8						8
#define EXTI_Line_9						9
#define EXTI_Line_10					10
#define EXTI_Line_11					11
#define EXTI_Line_12					12
#define EXTI_Line_13					13
#define EXTI_Line_14					14
#define EXTI_Line_15					15

/*@ref EXTI_Trigger_defined*/
#define EXTI_Trigger_Falling			1 /*Falling Edge*/
#define EXTI_Trigger_Rising				2 /*Rising Edge*/
#define EXTI_Trigger_Both				3 /*Both falling and rising edge*/

/*@ref EXTI_Status_defined*/
#define EXTI_Status_disable				0 /*If you want to disable an interrupt,
 	 	 	 	 	 	 	 	 	 	 	 you most probably don't care about it's configuration*/
#define EXTI_Status_Configure_disable	1 /*Configure an interrupt and disable it for now*/

#define EXTI_Status_enable				2 /*Configure and enable an interrupt*/

/*@ref EXTI_Mapping_defined*/
#define EXTI_Mapping_PA0				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_0 , EXTI_Line_0 }
#define EXTI_Mapping_PA1				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_1 , EXTI_Line_1 }
#define EXTI_Mapping_PA2				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_2 , EXTI_Line_2 }
#define EXTI_Mapping_PA3				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_3 , EXTI_Line_3 }
#define EXTI_Mapping_PA4				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_4 , EXTI_Line_4 }
#define EXTI_Mapping_PA5				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_5 , EXTI_Line_5 }
#define EXTI_Mapping_PA6				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_6 , EXTI_Line_6 }
#define EXTI_Mapping_PA7				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_7 , EXTI_Line_7 }
#define EXTI_Mapping_PA8				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_8 , EXTI_Line_8 }
#define EXTI_Mapping_PA9				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_9 , EXTI_Line_9 }
#define EXTI_Mapping_PA10				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_10, EXTI_Line_10}
#define EXTI_Mapping_PA11				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_11, EXTI_Line_11}
#define EXTI_Mapping_PA12				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_12, EXTI_Line_12}
#define EXTI_Mapping_PA13				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_13, EXTI_Line_13}
#define EXTI_Mapping_PA14				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_14, EXTI_Line_14}
#define EXTI_Mapping_PA15				(EXTI_PinMapping_t){GPIOA, GPIO_PIN_15, EXTI_Line_15}

#define EXTI_Mapping_PB0				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_0 , EXTI_Line_0 }
#define EXTI_Mapping_PB1				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_1 , EXTI_Line_1 }
#define EXTI_Mapping_PB2				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_2 , EXTI_Line_2 }
#define EXTI_Mapping_PB3				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_3 , EXTI_Line_3 }
#define EXTI_Mapping_PB4				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_4 , EXTI_Line_4 }
#define EXTI_Mapping_PB5				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_5 , EXTI_Line_5 }
#define EXTI_Mapping_PB6				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_6 , EXTI_Line_6 }
#define EXTI_Mapping_PB7				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_7 , EXTI_Line_7 }
#define EXTI_Mapping_PB8				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_8 , EXTI_Line_8 }
#define EXTI_Mapping_PB9				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_9 , EXTI_Line_9 }
#define EXTI_Mapping_PB10				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_10, EXTI_Line_10}
#define EXTI_Mapping_PB11				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_11, EXTI_Line_11}
#define EXTI_Mapping_PB12				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_12, EXTI_Line_12}
#define EXTI_Mapping_PB13				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_13, EXTI_Line_13}
#define EXTI_Mapping_PB14				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_14, EXTI_Line_14}
#define EXTI_Mapping_PB15				(EXTI_PinMapping_t){GPIOB, GPIO_PIN_15, EXTI_Line_15}
/*Stm32F103C6 LQFP48 has only PC[13-15]*/
#define EXTI_Mapping_PC13				(EXTI_PinMapping_t){GPIOC, GPIO_PIN_13, EXTI_Line_13}
#define EXTI_Mapping_PC14				(EXTI_PinMapping_t){GPIOC, GPIO_PIN_14, EXTI_Line_14}
#define EXTI_Mapping_PC15				(EXTI_PinMapping_t){GPIOC, GPIO_PIN_15, EXTI_Line_15}
/*Stm32F103C6 LQFP48 has only PD[0-1]*/
#define EXTI_Mapping_PD0				(EXTI_PinMapping_t){GPIOD, GPIO_PIN_0 , EXTI_Line_0 }
#define EXTI_Mapping_PD1				(EXTI_PinMapping_t){GPIOD, GPIO_PIN_1 , EXTI_Line_1 }
/*********************************************************************
 * 				APIs Supported by "MCAL EXTI DRIVER"				*
*********************************************************************/
void MCAL_EXTIx_Configure(EXTI_Config_t*);
EXTI_PinMapping_t MCAL_EXTIx_GetPinMapping(GPIO_T*,uint8_t);
void MCAL_EXTI_DeInit(void);

#endif /* INC_STM32F103C6_EXTI_DRIVER_H_ */
