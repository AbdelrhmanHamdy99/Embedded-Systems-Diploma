/*
 * KeyPad.h
 *
 * Created: 1/30/2025 9:39:32 PM
 *  Author: AbdoHamdy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
/******************************************************************
							Includes
******************************************************************/
#include "stm32f103c6_GPIO_Driver.h"
#include "stm32f103x6.h"
/*****************************************************************
 * 						KeyPad Parameters						*
******************************************************************/
#define n_Rows           4
#define n_Cols           4

extern const char KeyPad_Character_Matrix[4][4];
/*****************************************************************
 * 					   KeyPad Pins Mapping						 *
******************************************************************/
#define KeyPad_Rows_Port   	GPIOA
#define KeyPad_RowA      	GPIO_PIN_7
#define KeyPad_RowB      	GPIO_PIN_6
#define KeyPad_RowC      	GPIO_PIN_5
#define KeyPad_RowD      	GPIO_PIN_4

#define KeyPad_Cols_Port   	GPIOA
#define KeyPad_Col1      	GPIO_PIN_3
#define KeyPad_Col2      	GPIO_PIN_2
#define KeyPad_Col3      	GPIO_PIN_1
#define KeyPad_Col4      	GPIO_PIN_0
/*****************************************************************
 * 				APIs Supported by "HAL KeyPad DRIVER"			*
******************************************************************/
void keyPad_Init(void);
char KeyPad_GetKeyPressed(void);


#endif /* KEYPAD_H_ */
