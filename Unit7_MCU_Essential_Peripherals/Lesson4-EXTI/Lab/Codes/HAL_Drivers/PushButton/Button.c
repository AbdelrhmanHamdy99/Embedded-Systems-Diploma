/*
 * Button.c
 *
 *  Created on: Feb 20, 2025
 *      Author: AbdoHamdy
 */


#include "Button.h"
#include "LCD.h"
#include "stm32f103c6_EXTI_Driver.h"
#include "stm32f103c6_GPIO_Driver.h"
#include "stm32f103x6.h"

uint8_t IRQ_happened = 0;
void Button_Init(void){
	GPIO_PinConfig_t buttonPinConfig; /*a structure to hold pin configuration*/
	EXTI_Config_t EXTIx_Config; /*a structure to hold EXTIx configuration*/

	/*1. enable clock for Button_Port*/
	switch ((uint32_t)Button_Port) {
	case (uint32_t)GPIOA:
		GPIOA_Clock_Enable;
		break;
	case (uint32_t)GPIOB:
		GPIOB_Clock_Enable;
		break;
	case (uint32_t)GPIOC:
		GPIOC_Clock_Enable;
		break;
	case (uint32_t)GPIOD:
		GPIOD_Clock_Enable;
		break;
	default:
		break;
	}
	/*2. enable AFIO Clock*/
	AFIO_Clock_Enable;
	/*3. configure button pin as input floating*/
	buttonPinConfig.pinNumber = Button_Pin;
	buttonPinConfig.pinMode	  = GPIO_PIN_MODE_IN_Floating;
	MCAL_GPIO_Init(Button_Port, &buttonPinConfig);
	/*4. Adjust EXTI configuration for Button pin*/
	EXTIx_Config.pinMapping      = MCAL_EXTIx_GetPinMapping(Button_Port, Button_Pin);
	EXTIx_Config.trigerringEdge  = EXTI_Trigger_Both;
	EXTIx_Config.interruptStatus = EXTI_Status_enable;
	EXTIx_Config.callback = Button_CallBack;
	MCAL_EXTIx_Configure(&EXTIx_Config);
}
void Button_CallBack(void){
	LCD_Write_Command(DDRAM_Address = F04);
	LCD_Write_Data("IRQ EXTI9 is -->");
	LCD_Write_Command(DDRAM_Address = S04);
	LCD_Write_Data("happened");
	IRQ_happened = 1;
}


