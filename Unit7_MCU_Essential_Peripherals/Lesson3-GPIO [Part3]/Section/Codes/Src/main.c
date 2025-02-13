/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "LCD.h"
#include "KeyPad.h"
#include "7Seg.h"
void clock_Init(void);
int main(void)
{
	LCD_Config_t LCD_Config;
	LCD_Config.Display_control = Display_Control_D_On_C_On_B_On;
	LCD_Config.Entry_mode      = Entry_Mode_Inc_No_S;
	LCD_Config.function_set    = Function_Set_4bit_2line_5x8;
	clock_Init();
	SevenSeg_Init(SevenSeg_Type_Com_An);
	keyPad_Init();
	LCD_Init(&LCD_Config);


	while (1)
	{
		char c = KeyPad_GetKeyPressed();
		switch (c) {
		case ' ':
			/*clear 7Seg*/
			SevenSeg_Clear();
			/*Clear Screen*/
			LCD_Write_Command(LCD_Clear);
			LCD_Write_Command(LCD_Return_Home);
			break;
		case 0:
			/*do nothing no character is pressed*/
			break;
		default:
			SevenSeg_DisplayNumber(c);
			LCD_SendCharacter(c);
			break;
		}
	}
}
void clock_Init(void){
	GPIOA_Clock_Enable;
	GPIOB_Clock_Enable;
}
