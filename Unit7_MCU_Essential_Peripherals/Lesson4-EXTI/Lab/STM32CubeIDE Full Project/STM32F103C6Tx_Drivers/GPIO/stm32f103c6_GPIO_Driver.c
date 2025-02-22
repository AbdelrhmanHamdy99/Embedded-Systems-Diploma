/*
 * stm32f103c6_GPIO_Driver.c
 *
 *  Created on: Feb 20, 2025
 *      Author: AbdoHamdy
 */


#include "stm32f103c6_GPIO_Driver.h"
#include <assert.h>
/****************************************************************************************************
 * @Fn			- MCAL_GPIO_Init
 * @brief		- Initializes GPIOx PINy according to required pinConfig
 * @Param [in]	- GPIOx: a pointer to the required GPIO Peripheral
 * 				  Can be a value of GPIO[A,B,C,D]
 * @Param [in]	- pinConfig: a pointer to a structure that contains pin configuration
 * @returnValue - None
 * Note			- None
 */
void MCAL_GPIO_Init(GPIO_T* GPIOx, GPIO_PinConfig_t* pinConfig){
	assert(pinConfig->pinNumber <= GPIO_PIN_15); /*GPIO has only 16 pin*/
	volatile uint32_t *gpioConfigReg =  pinConfig->pinNumber < 8 ? &(GPIOx->CRL) : &(GPIOx->CRH);

	switch (pinConfig->pinMode) {
	case GPIO_PIN_MODE_Out_PushPull:
	case GPIO_PIN_MODE_Out_OpenDrain:
	case GPIO_PIN_MODE_AF_Out_PushPull:
	case GPIO_PIN_MODE_AF_Out_OpenDrain:
		/*GPIO speed must be <= 50MHZ*/
		assert(pinConfig->pinOutSpeed <= GPIO_PIN_OUT_SPEED_50MHZ);
		/*Reset Mode[1:0] & CNF[1:0]*/
		*gpioConfigReg &= ~(0xF << ((pinConfig->pinNumber % GPIO_PIN_8)*4));
		/*MODE[1:0]*/
		*gpioConfigReg |= (pinConfig->pinOutSpeed << ((pinConfig->pinNumber % GPIO_PIN_8) * 4));
		/*CNF[1:0]*/
		*gpioConfigReg |= (pinConfig->pinMode << ((pinConfig->pinNumber % GPIO_PIN_8) * 4) << 2);
		break;
	case GPIO_PIN_MODE_IN_Analog:
	case GPIO_PIN_MODE_IN_Floating:
		/*Reset Mode[1:0] & CNF[1:0]*/
		*gpioConfigReg &= ~(0xF << ((pinConfig->pinNumber % GPIO_PIN_8)*4));
		/*CNF[1:0]*/
		*gpioConfigReg |= ((pinConfig->pinMode-4) << ((pinConfig->pinNumber % GPIO_PIN_8) * 4) << 2);
		break;
	case GPIO_PIN_MODE_IN_PullDown:
		/*Reset Mode[1:0] & CNF[1:0]*/
		*gpioConfigReg &= ~(0xF << ((pinConfig->pinNumber % GPIO_PIN_8)*4));
		/*CNF[1:0] = 2 & ODR = 0*/
		*gpioConfigReg |= ((GPIO_PIN_MODE_IN_PullDown-4) << ((pinConfig->pinNumber % GPIO_PIN_8) * 4) << 2);
		GPIOx->ODR &= ~(1<<pinConfig->pinNumber);
		break;
	case GPIO_PIN_MODE_IN_PullUp:
		/*Reset Mode[1:0] & CNF[1:0]*/
		*gpioConfigReg &= ~(0xF << ((pinConfig->pinNumber % GPIO_PIN_8)*4));
		/*CNF[1:0] = 2 & ODR = 1*/
		*gpioConfigReg |= ((GPIO_PIN_MODE_IN_PullDown-4) << ((pinConfig->pinNumber % GPIO_PIN_8) * 4) << 2);
		GPIOx->ODR |= (1<<pinConfig->pinNumber);
		break;
	default:
		break;
	}

}
/*****************************************************************************************************************
 * @Fn			- MCAL_GPIO_DeInit
 * @brief		- Restore Initial configurations for a required GPIO peripheral
 * @Param [in]	- GPIOx : a pointer to the required GPIO Peripheral
 * 				  Can be a value of GPIO[A,B,C,D]
 * @returnValue - None
 * Notes		- None
 */
void MCAL_GPIO_DeInit(GPIO_T* GPIOx){
	/*use the reset circuit*/
	switch((uint32_t)GPIOx){
	case (uint32_t)GPIOA:
		RCC->APB2RSTR |= (1<<2);
		break;
	case (uint32_t)GPIOB:
		RCC->APB2RSTR |= (1<<3);
		break;
	case (uint32_t)GPIOC:
		RCC->APB2RSTR |= (1<<4);
		break;
	case (uint32_t)GPIOD:
		RCC->APB2RSTR |= (1<<5);
		break;
	default:
		/*do nothing*/
		break;
	}
}
/****************************************************************************************************
 * @Fn			- MCAL_GPIO_ReadPin
 * @brief		- Reads GPIOx PINy value
 * @Param [in]	- GPIOx : a pointer to the required GPIO Peripheral
 * 				  Can be a value of GPIO[A,B,C,D]
 * @Param [in]	- pinNumber : defines the pin to read
 * 				  Can be a value of @ref GPIO_PIN_define
 * @returnValue	- the value of the required pin
 * 				  Can be a value of @ref GPIO_PIN_Value_define
 * Notes		- None
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_T* GPIOx,uint8_t pinNumber){
	assert(pinNumber <= GPIO_PIN_15);
	return (GPIOx->IDR >> pinNumber) & GPIO_PIN_Value_High;
}

/****************************************************************************************************
 * @Fn			- MCAL_GPIO_ReadPort
 * @brief		- Reads GPIOx value
 * @Param [in]	- GPIOx : a pointer to the required GPIO Peripheral
 * 				  Can be a value of GPIO[A,B,C,D]
 * @returnValue	- The value of GPIOx Port
 * Notes		- None
 */
uint16_t 	MCAL_GPIO_ReadPort(GPIO_T *GPIOx){
	return (uint16_t)GPIOx->IDR;
}

/****************************************************************************************************
 * @Fn			- MCAL_GPIO_WritePin
 * @brief		- Writes GPIOx PINy value
 * @Param [in]	- GPIOx : a pointer to the required GPIO Peripheral
 * 				  Can be a value of GPIO[A,B,C,D]
 * @Param [in]	- pinNumber : defines the pin to be written
 * 				  Can be a value of @ref GPIO_PIN_define
 * @Param [in]	- val : the value to be written on the pin
 * 				  Can be a value of @ref GPIO_PIN_Value_define
 * @returnValue	- None
 * Notes		- None
 */
void MCAL_GPIO_WritePin(GPIO_T* GPIOx, uint8_t pinNumber,uint8_t val){
	assert(pinNumber <= GPIO_PIN_15);  /*GPIO has only 16 pin*/
	switch(val){
	case GPIO_PIN_Value_High:
		GPIOx->BSRR = (1 << pinNumber);
		break;
	case GPIO_PIN_Value_Low:
		GPIOx->BRR = (1 << pinNumber);
		break;
	default:
		/*do nothing*/
		break;
	}
}
/****************************************************************************************************
 * @Fn			- MCAL_GPIO_ReadPin
 * @brief		- Writes a val to GPIOx
 * @Param [in]	- GPIOx : a pointer to the required GPIO Peripheral
 * 				  		  Can be a value of GPIO[A,B,C,D]
 * @Param [in]	- val : a 16-bit value to be written on GPIOx
 * @returnValue	- None
 * Notes		- None
 */
void MCAL_GPIO_WritePort(GPIO_T* GPIOx, uint16_t val){
	GPIOx->ODR = val;
}
/****************************************************************************************************
 * @Fn 			- MCAL_GPIO_TogglePin
 * @brief		- Toggles Portx Piny value
 * @param [in]	- GPIOx : a pointer to the required GPIO Peripheral
 * 				  Can be a value of GPIO[A,B,C,D]
 * @Param [in]	- pinNumber : defines the pin to be toggled
 * 				  Can be a value of @ref GPIO_PIN_define
 * @returnValue	- None
 * Notes		- None
 */
void MCAL_GPIO_TogglePin(GPIO_T* GPIOx,uint8_t pinNumber){
	assert(pinNumber <= GPIO_PIN_15);
	GPIOx->ODR ^= (1<<pinNumber);
}
/****************************************************************************************************
 * @Fn 			- MCAL_GPIO_TogglePort
 * @brief		- Toggles Portx value
 * @param [in]	- GPIOx : a pointer to the required GPIO Peripheral
 * 				  Can be a value of GPIO[A,B,C,D]
 * @returnValue	- None
 * Notes		- None
 */
void MCAL_GPIO_TogglePort(GPIO_T* GPIOx){
	GPIOx->ODR ^= 0xFF;
}
/****************************************************************************************************
 * @Fn 			- MCAL_GPIO_LockPin
 * @brief		- Locks Portx PINy value
 * @param [in]	- GPIOx : a pointer to the required GPIO Peripheral
 * 				  Can be a value of GPIO[A,B,C,D]
 * @Param [in]	- pinNumber : defines the pin to be locked
 * 				  Can be a value of @ref GPIO_PIN_define
 * @returnValue	- None
 * Notes		- None
 */
void MCAL_GPIO_LockPin(GPIO_T* GPIOx,uint8_t pinNumber){
	assert(pinNumber <= GPIO_PIN_15);
	/*lock the configuration of the port bits
	when a correct write sequence is applied to bit 16 (LCKK).*/
	GPIOx->LCKR &= ~(1<<16); /*Port configuration lock key not active*/
	GPIOx->LCKR |= (1 << pinNumber); /*Lock the required pin
									   Can only be written when the LCKK bit is 0.*/
	/*Apply LOCK key writing sequence:*/
	GPIOx->LCKR |=  (1<<16); /*Write 1*/
	GPIOx->LCKR &= ~(1<<16); /*Write 0*/
	GPIOx->LCKR |=  (1<<16); /*Write 1*/
	assert(!GPIOx->LCKR);    /*read 0*/
	assert(GPIOx->LCKR);     /*read 1*/
}




