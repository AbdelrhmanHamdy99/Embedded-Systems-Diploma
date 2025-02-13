/*
 * 7Seg.h
 *
 *  Created on: Feb 13, 2025
 *      Author: AbdoHamdy
 */

#ifndef INC_7SEG_H_
#define INC_7SEG_H_
/****************************************************************
 * 							Includes							*
 ****************************************************************/
#include "stm32f103c6_GPIO_Driver.h"
#include "stm32f103x6.h"
#include <stdint.h>
/****************************************************************
 * 					   7Seg Pins Mapping						*
 ****************************************************************/
#define SevenSegPort			GPIOB
#define SevenSeg_a				GPIO_PIN_3
#define SevenSeg_b				GPIO_PIN_4
#define SevenSeg_c				GPIO_PIN_5
#define SevenSeg_d				GPIO_PIN_6
#define SevenSeg_e				GPIO_PIN_7
#define SevenSeg_f				GPIO_PIN_8
#define SevenSeg_g				GPIO_PIN_9

#define SevenSeg_nPins			7
/*****************************************************************
 * 				Macros Configuration References					*
******************************************************************/
/*@ref SevenSeg_Type_defined*/
#define SevenSeg_Type_Com_An 	0 /*Common Anode*/
#define SevenSeg_Type_Com_Cath 	1 /*Common Cathode*/
/****************************************************************
 * 				APIs Supported by "HAL 7Seg DRIVER"				*
 ****************************************************************/
void SevenSeg_Init(uint8_t);
void SevenSeg_DisplayNumber(char num);
void SevenSeg_Clear(void);

#endif /* INC_7SEG_H_ */
