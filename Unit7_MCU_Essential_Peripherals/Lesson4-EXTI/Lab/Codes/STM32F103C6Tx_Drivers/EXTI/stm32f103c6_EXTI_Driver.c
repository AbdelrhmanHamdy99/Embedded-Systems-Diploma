/*
 * stm32f103c6_EXTI_Driver.c
 *
 *  Created on: Feb 20, 2025
 *      Author: AbdoHamdy
 */



#include "stm32f103c6_EXTI_Driver.h"
#include "stm32f103c6_GPIO_Driver.h"
#include "stm32f103x6.h"
#include "Utils.h"
#include <assert.h>

void (*PF[15])(void) = {NULL}; /*array that hold pointers to callback functions*/
static uint8_t Enabled_Interrupts[11] = {0}; /*array to hold which an interrupt is enabled or not*/

void NVIC_EXTIx_Enable(uint8_t);
void NVIC_EXTIx_Disable(uint8_t);
/*
 * @Fn			- MCAL_EXTIx_Configure
 * @brief		- Configure an external interrupt
 * @param [in]	- EXTIx_config : a pointer to a structure that contains the configurations
 * @returnValue	- None
 * @Notes		- The User Must enable The clock for GPIOx, AFIO
 * 				  In case Of invalid Configuration Values:
 * 				  interruptStatus  		= EXTI_Status_Configure_disable
 * 				  trigerringEdge   		= unKnown behavior
 * 				  pinMapping.GPIOx 		= GPIOA
 * 				  pinMapping.EXTI_Line 	= Error
 * 				  pinMapping.pinNumber 	= Error
 */
void MCAL_EXTIx_Configure(EXTI_Config_t* EXTIx_config){
	uint8_t mapVal; /*variable to hold mapping value according to GPIO number*/
	/*Fire error in case of Invalid EXTI_Line or pinNumber*/
	assert(EXTIx_config->pinMapping.EXTI_Line == EXTIx_config->pinMapping.pinNumber);
	assert(EXTIx_config->pinMapping.EXTI_Line <= EXTI_Line_15);

	/*1. Enable or disable EXTIx*/
	if(EXTIx_config->interruptStatus == EXTI_Status_enable){
		/*Enable EXTIx*/
		EXTI->IMR |= (1<<EXTIx_config->pinMapping.EXTI_Line);
		/*Enable NVIC Line for EXTIx*/
		NVIC_EXTIx_Enable(EXTIx_config->pinMapping.EXTI_Line);
	}else{
		/*Disable EXTIx*/
		EXTI->IMR &= ~(1<<EXTIx_config->pinMapping.EXTI_Line);
		/*Disable NVIC Line for EXTIx*/
		NVIC_EXTIx_Disable(EXTIx_config->pinMapping.EXTI_Line);
		/*just disable a pre-enabled interrupt without changing it's configuration*/
		if(EXTIx_config->interruptStatus == EXTI_Status_disable)
			return;
	}
	/*2. Adjust Triggering Event*/
	/*2.1. reset triggering event*/
	EXTI->FTSR &= ~(1<<EXTIx_config->pinMapping.EXTI_Line);
	EXTI->RTSR &= ~(1<<EXTIx_config->pinMapping.EXTI_Line);
	/*2.2. fire the chosen one*/
	EXTI->FTSR |= ((EXTIx_config->trigerringEdge & EXTI_Trigger_Falling)<<EXTIx_config->pinMapping.EXTI_Line);
	EXTI->RTSR |= ((EXTIx_config->trigerringEdge & EXTI_Trigger_Rising )<<(EXTIx_config->pinMapping.EXTI_Line - 1));

	/*3. adjust pin mapping*/
	/*3.1. get the mapping value*/
	mapVal = (EXTIx_config->pinMapping.GPIOx == GPIOA) ? 0 : \
			(EXTIx_config->pinMapping.GPIOx == GPIOB) ? 1 : \
					(EXTIx_config->pinMapping.GPIOx == GPIOC) ? 2 : \
							(EXTIx_config->pinMapping.GPIOx == GPIOD) ? 3 : 0;
	/*3.2. Clear the nibble that correspond to EXTIx*/
	AFIO->EXTICR[EXTIx_config->pinMapping.EXTI_Line / 4] &= ~(0xF    << ((EXTIx_config->pinMapping.EXTI_Line % 4)*4));
	/*3.3. update the nibble that correspond to EXTIx with the desired mapping*/
	AFIO->EXTICR[EXTIx_config->pinMapping.EXTI_Line / 4] |=  (mapVal << ((EXTIx_config->pinMapping.EXTI_Line % 4)*4));
	/*4. update Callback Function*/
	PF[EXTIx_config->pinMapping.EXTI_Line] = EXTIx_config->callback;
}

/*
 * @Fn			- MCAL_EXTIx_GetPinMapping
 * @brief		- Get the right mapping value for a given GPIO port and pin
 * @param [in]	- GPIOx 	: a pointer to the required GPIO Peripheral
 * @param [in]	- pinNmber 	: the number of the pin to be configured as EXTI
 * @returnValue	- None
 * @Notes		- None
 */
EXTI_PinMapping_t MCAL_EXTIx_GetPinMapping(GPIO_T* GPIOx,uint8_t pinNmber){
	EXTI_PinMapping_t GPIOxPinyEXTIz; /*a structure to hold the desired pin mapping*/
	GPIOxPinyEXTIz = EXTI_Mapping_PA0;
	switch (pinNmber) {
	case GPIO_PIN_0:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA0;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB0;
			break;
		case (uint32_t)GPIOD:
			GPIOxPinyEXTIz = EXTI_Mapping_PD0;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_1:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA1;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB1;
			break;
		case (uint32_t)GPIOD:
			GPIOxPinyEXTIz = EXTI_Mapping_PD1;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_2:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA2;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB2;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_3:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA3;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB3;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_4:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA4;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB4;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_5:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA5;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB5;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_6:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA6;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB6;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_7:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA7;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB7;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_8:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA8;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB8;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_9:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA9;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB9;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_10:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA10;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB10;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_11:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA11;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB11;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_12:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA12;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB12;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_13:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA13;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB13;
			break;
		case (uint32_t)GPIOC:
			GPIOxPinyEXTIz = EXTI_Mapping_PC13;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_14:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA14;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB14;
			break;
		case (uint32_t)GPIOC:
			GPIOxPinyEXTIz = EXTI_Mapping_PC14;
			break;
		default:
			break;
		}
		break;
	case GPIO_PIN_15:
		switch ((uint32_t)GPIOx) {
		case (uint32_t)GPIOA:
			GPIOxPinyEXTIz = EXTI_Mapping_PA15;
			break;
		case (uint32_t)GPIOB:
			GPIOxPinyEXTIz = EXTI_Mapping_PB15;
			break;
		case (uint32_t)GPIOC:
			GPIOxPinyEXTIz = EXTI_Mapping_PC15;
			break;
		default:
			break;
		}
		break;
		default:
			break;
	}
	return GPIOxPinyEXTIz;
}
/*
 * @Fn			- EXTIx_DeInit
 * @brief		- Restore Initial configurations for EXTI
 * @param [in]	- EXTIx_config : a pointer to a structure that contains the configurations
 * @returnValue	- None
 * @Notes		- In case Of invalid Configuration Values:
 * 				  interruptStatus  		= EXTI_Status_Configure_disable
 * 				  trigerringEdge   		= unKnown behavior
 * 				  pinMapping.GPIOx 		= GPIOD
 * 				  pinMapping.EXTI_Line 	= Error
 * 				  pinMapping.pinNumber 	= Error
 */
void MCAL_EXTI_DeInit(void){
	uint8_t i; /*iterator*/
	/*reset values for EXTI registers*/
	EXTI->IMR  = 0;
	EXTI->EMR  = 0;
	EXTI->RTSR = 0;
	EXTI->FTSR = 0;
	EXTI->SWIER= 0;
	EXTI->PR   = 0xFFFF; /*Clear by Writing 1
	 	 	 	 	 	   Only 16 bit represents EXTI*/
	/*reset Values For AFIO_EXTICR registers*/
	AFIO->EXTICR[0] = 0;
	AFIO->EXTICR[1] = 0;
	AFIO->EXTICR[2] = 0;
	AFIO->EXTICR[3] = 0;
	/*Disable NVIC EXTI Lines*/
	NVIC->ICER[0] |= ((1<<NVIC_EXTI0_IRQ_Line) | (1<<NVIC_EXTI1_IRQ_Line) | (1<<NVIC_EXTI2_IRQ_Line) |\
			(1<<NVIC_EXTI3_IRQ_Line) | (1<<NVIC_EXTI4_IRQ_Line) | (1<<NVIC_EXTI9_5_IRQ_Line));
	NVIC->ICER[1] |= (1<< NVIC_EXTI15_10_IRQ_Line % register_Size);

	/*Zero the EnabledInterrupts array && NULL the PF array*/
	for(i = 0 ; i < 11; i++){
		Enabled_Interrupts [i] = 0;
		PF[i] = NULL;
	}
	while(i < 15)
		PF[i++] = NULL;
}

void NVIC_EXTIx_Enable(uint8_t EXTIx){
	switch(EXTIx){
	case EXTI_Line_0 :
		NVIC->ISER[NVIC_EXTI0_IRQ_Line / register_Size] |= (1<< NVIC_EXTI0_IRQ_Line % register_Size);
		break;
	case EXTI_Line_1 :
		NVIC->ISER[NVIC_EXTI1_IRQ_Line / register_Size] |= (1<< NVIC_EXTI1_IRQ_Line % register_Size);
		break;
	case EXTI_Line_2 :
		NVIC->ISER[NVIC_EXTI2_IRQ_Line / register_Size] |= (1<< NVIC_EXTI2_IRQ_Line % register_Size);
		break;
	case EXTI_Line_3 :
		NVIC->ISER[NVIC_EXTI3_IRQ_Line / register_Size] |= (1<< NVIC_EXTI3_IRQ_Line % register_Size);
		break;
	case EXTI_Line_4 :
		NVIC->ISER[NVIC_EXTI4_IRQ_Line / register_Size] |= (1<< NVIC_EXTI4_IRQ_Line % register_Size);
		break;
	case EXTI_Line_5 :
	case EXTI_Line_6 :
	case EXTI_Line_7 :
	case EXTI_Line_8 :
	case EXTI_Line_9 :
		Enabled_Interrupts[EXTIx - 5] = 1;
		NVIC->ISER[NVIC_EXTI9_5_IRQ_Line / register_Size] |= (1<< NVIC_EXTI9_5_IRQ_Line % register_Size);
		break;
	case EXTI_Line_10:
	case EXTI_Line_11:
	case EXTI_Line_12:
	case EXTI_Line_13:
	case EXTI_Line_14:
	case EXTI_Line_15:
		Enabled_Interrupts[EXTIx - 5] = 1;
		NVIC->ISER[NVIC_EXTI15_10_IRQ_Line/register_Size] |= (1<< NVIC_EXTI15_10_IRQ_Line % register_Size);
		break;
	}
}
void NVIC_EXTIx_Disable(uint8_t EXTIx){
	uint8_t i = 0;
	switch(EXTIx){
	case EXTI_Line_0 :
		NVIC->ICER[NVIC_EXTI0_IRQ_Line / register_Size] |= (1<< NVIC_EXTI0_IRQ_Line % register_Size);
		break;
	case EXTI_Line_1 :
		NVIC->ICER[NVIC_EXTI1_IRQ_Line / register_Size] |= (1<< NVIC_EXTI1_IRQ_Line % register_Size);
		break;
	case EXTI_Line_2 :
		NVIC->ICER[NVIC_EXTI2_IRQ_Line / register_Size] |= (1<< NVIC_EXTI2_IRQ_Line % register_Size);
		break;
	case EXTI_Line_3 :
		NVIC->ICER[NVIC_EXTI3_IRQ_Line / register_Size] |= (1<< NVIC_EXTI3_IRQ_Line % register_Size);
		break;
	case EXTI_Line_4 :
		NVIC->ICER[NVIC_EXTI4_IRQ_Line / register_Size] |= (1<< NVIC_EXTI4_IRQ_Line % register_Size);
		break;
	case EXTI_Line_5 :
	case EXTI_Line_6 :
	case EXTI_Line_7 :
	case EXTI_Line_8 :
	case EXTI_Line_9 :
		Enabled_Interrupts[EXTIx - 5] = 0;
		for(i = 0 ; i < 5 ; i++){
			if(Enabled_Interrupts[i] == 1) /*there is an active interrupt*/
				return;
		}
		NVIC->ICER[NVIC_EXTI9_5_IRQ_Line / register_Size] |= (1<< NVIC_EXTI9_5_IRQ_Line % register_Size);
		break;
	case EXTI_Line_10:
	case EXTI_Line_11:
	case EXTI_Line_12:
	case EXTI_Line_13:
	case EXTI_Line_14:
	case EXTI_Line_15:
		Enabled_Interrupts[EXTIx - 5] = 0;
		for(i = 5 ; i < 11 ; i++){
			if(Enabled_Interrupts[i] == 1) /*there is an active interrupt*/
				return;
		}
		NVIC->ICER[NVIC_EXTI15_10_IRQ_Line/register_Size] |= (1<< NVIC_EXTI15_10_IRQ_Line % register_Size);
		break;
	}
}

/*EXTIs Interrupt Handlers @ref "startup_stm32f103c6tx.s" */
void EXTI0_IRQHandler(void){ /* EXTI Line0 interrupt */
	EXTI->PR |= (1<<EXTI_Line_0);
	PF[0]();
}
void EXTI1_IRQHandler(void){ /* EXTI Line1 interrupt */
	EXTI->PR |= (1<<EXTI_Line_1); /*remove the pending bit*/
	PF[1](); /*Call the CallBack Function*/
}
void EXTI2_IRQHandler(void){ /* EXTI Line2 interrupt */
	EXTI->PR |= (1<<EXTI_Line_2); /*remove the pending bit*/
	PF[2](); /*Call the CallBack Function*/
}
void EXTI3_IRQHandler(void){ /* EXTI Line3 interrupt */
	EXTI->PR |= (1<<EXTI_Line_3); /*remove the pending bit*/
	PF[3](); /*Call the CallBack Function*/
}
void EXTI4_IRQHandler(void){ /* EXTI Line4 interrupt */
	EXTI->PR |= (1<<EXTI_Line_4);/*remove the pending bit*/
	PF[4](); /*Call the CallBack Function*/
}
void EXTI9_5_IRQHandler(void){ /* EXTI Line5-9 interrupt */
	uint8_t i = 5; /*iterator*/
	while(i < 10){
		if(EXTI->PR & (1 << i)){ /*iterate to find which line caused the interrupt*/
			EXTI->PR |= (1<<i); /*remove the pending bit*/
			PF[i](); /*Call the CallBack Function*/
			break;
		}
		i++;
	}
}
void EXTI15_10_IRQHandler(void){ /* EXTI Line10-15 interrupt */
	uint8_t i = 10; /*iterator*/
	while(i < 16){
		if(EXTI->PR & (1 << i)){ /*iterate to find which line caused the interrupt*/
			EXTI->PR |= (1<<i); /*remove the pending bit*/
			PF[i](); /*Call the CallBack Function*/
			break;
		}
		i++;
	}
}
