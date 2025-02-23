/*
 * Button.h
 *
 *  Created on: Feb 20, 2025
 *      Author: AbdoHamdy
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

/****************************************************************
 * 							Includes							*
*****************************************************************/
#include "stm32f103c6_EXTI_Driver.h"
#include "stm32f103c6_GPIO_Driver.h"
#include "stm32f103x6.h"
/****************************************************************
 * 					   Buttons Pins Mapping						*
*****************************************************************/
#define Button_Port				GPIOB
#define Button_Pin				GPIO_PIN_9
/********************************************************************
 * 							Global Variables						*
*********************************************************************/
extern uint8_t IRQ_happened;
/********************************************************************
 * 				APIs Supported by "HAL Button DRIVER"				*
*********************************************************************/
void Button_Init(void);
void Button_CallBack(void);




#endif /* INC_BUTTON_H_ */
