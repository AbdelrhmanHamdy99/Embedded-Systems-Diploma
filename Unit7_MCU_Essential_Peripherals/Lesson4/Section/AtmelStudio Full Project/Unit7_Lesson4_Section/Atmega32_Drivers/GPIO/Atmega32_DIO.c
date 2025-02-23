/*
 * Atmega32_DIO.c
 *
 * Created: 2/22/2025 9:14:43 PM
 *  Author: AbdoHamdy
 */ 

#include "Atmega32.h"
#include "Atmega32_DIO.h"
#include <stdint.h>

/****************************************************************************************************
 * @Fn			- MCAL_DIO_Init
 * @brief		- Initializes DIOx PINy according to required pinConfig
 * @Param [in]	- DIOx: a pointer to the required DIO Peripheral
 * 				  Can be a value of DIO[A,B,C,D]
 * @Param [in]	- pinConfig: a pointer to a structure that contains pin configuration
 * @returnValue - None
 * Note			- default pinMode = DIO_PinMode_In_Floating
 */
void MCAL_DIO_Init(DIO_T* DIOx, DIO_PinConfig_T* pinConfig){
	if(pinConfig->pinNumber == DIO_Pin_Not_Used)
		return ;
	switch(pinConfig->pinMode){
		case DIO_PinMode_Out:
			DIOx->DDR |= (1 << pinConfig->pinNumber);
			break;
		case DIO_PinMode_In_Pull_Up:
			DIOx->PORT |=  (1<<pinConfig->pinNumber); /*activate Pull-Up resistor*/
			DIOx->DDR  &= ~(1<<pinConfig->pinNumber);
			break;
		default:
			DIOx->PORT &= ~(1<<pinConfig->pinNumber); /*deactivate Pull-Up resistor*/
			DIOx->DDR  &= ~(1<<pinConfig->pinNumber); 
			break;		
	}
}
/****************************************************************************************************
 * @Fn			- MCAL_DIO_WritePin
 * @brief		- updates DIOx PINy value
 * @Param [in]	- DIOx: a pointer to the required DIO Peripheral
 * 				  Can be a value of DIO[A,B,C,D]
 * @Param [in]	- Piny: the number of the pin to be updated
 *				  Can be a value of @ref DIO_Pin_defined
 * @Param [in]	- value: the value to be written on DIOx Piny
 *				  Can be a value of @ref DIO_PinValue_defined
 * @returnValue - None
 * Note			- None
 */
void MCAL_DIO_WritePin(DIO_T* DIOx,uint8_t Piny,uint8_t value){
	if(Piny == DIO_Pin_Not_Used)
		return ;
	switch(value){
		case DIO_PinValue_High :
			DIOx->PORT |= (1<< Piny);
			break;
		case DIO_PinValue_Low :
			DIOx->PORT &= ~(1<< Piny);
			break;
		default:
			break;
	}
}
/****************************************************************************************************
 * @Fn			- MCAL_DIO_WritePort
 * @brief		- updates the whole DIOx value
 * @Param [in]	- DIOx: a pointer to the required DIO Peripheral
 * 				  Can be a value of DIO[A,B,C,D]
 * @Param [in]	- value: the value to be written on DIOx
 * @returnValue - None
 * Note			- None
 */
void MCAL_DIO_WritePort(DIO_T* DIOx,uint8_t value){
	DIOx->PORT = value;
}
/****************************************************************************************************
 * @Fn			- MCAL_DIO_ReadPin
 * @brief		- Reads the value of DIOx Piny
 * @Param [in]	- DIOx: a pointer to the required DIO Peripheral
 * 				  Can be a value of DIO[A,B,C,D]
 * @Param [in]	- Piny: the number of the pin to be read
 *				  Can be a value of @ref DIO_Pin_defined
 * @returnValue - the current value of DIOx Piny
 *				  Can be a value of @ref DIO_PinValue_defined
 * Note			- None
 */
uint8_t	MCAL_DIO_ReadPin(DIO_T* DIOx,uint8_t Piny){
	return (DIOx->PIN >> Piny ) & 1;
}
/****************************************************************************************************
 * @Fn			- MCAL_DIO_ReadPort
 * @brief		- Reads the whole DIOx value
 * @Param [in]	- DIOx: a pointer to the required DIO Peripheral to be read
 * 				  Can be a value of DIO[A,B,C,D]
 * @returnValue - the current value of DIOx Port
 * Note			- None
 */
uint8_t	MCAL_DIO_ReadPort (DIO_T* DIOx){
	return DIOx->PIN;
}
