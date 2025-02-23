/*
 * Atmega32_DIO.h
 *
 * Created: 2/22/2025 5:18:24 PM
 *  Author: AbdoHamdy
 */ 


#ifndef ATMEGA32_DIO_H_
#define ATMEGA32_DIO_H_

/****************************************************************
 *							Includes							*
 ****************************************************************/
#include "Atmega32.h"
/****************************************************************
 *						User Defined Structures					*
 ****************************************************************/
typedef struct {
	uint8_t pinNumber	;	/*Specifies the pin number to be configured
							Can be a value of @ref DIO_Pin_defined*/
	uint8_t pinMode		;	/*Specifies the mode of the desired pin
							Can be a value of @ref DIO_PinMode_defined*/
	}DIO_PinConfig_T;
/****************************************************************
 * 				Macros Configuration References					*
*****************************************************************/
/*@ref DIO_Pin_defined*/
#define DIO_Pin_0				0
#define DIO_Pin_1				1
#define DIO_Pin_2				2
#define DIO_Pin_3				3
#define DIO_Pin_4				4
#define DIO_Pin_5				5
#define DIO_Pin_6				6
#define DIO_Pin_7				7
#define DIO_Pin_8				8
#define DIO_Pin_Not_Used	   -1 /*this value is mainly for HAL Layer Components that has pins not used 
									or not connected to the MCU*/
/*@ref DIO_PinMode_defined*/ 
#define DIO_PinMode_Out			0
#define DIO_PinMode_In_Floating	1
#define DIO_PinMode_In_Pull_Up	2
/*@ref DIO_PinValue_defined*/
#define DIO_PinValue_Low		0
#define DIO_PinValue_High		1
/********************************************************************
 * 				APIs Supported by "MCAL DIO DRIVER"				*
*********************************************************************/
void	MCAL_DIO_Init		(DIO_T*,DIO_PinConfig_T*);
void	MCAL_DIO_WritePin	(DIO_T*,uint8_t,uint8_t);
void	MCAL_DIO_WritePort	(DIO_T*,uint8_t);
uint8_t	MCAL_DIO_ReadPin	(DIO_T*,uint8_t);
uint8_t	MCAL_DIO_ReadPort	(DIO_T*);

#endif /* ATMEGA32_DIO_H_ */