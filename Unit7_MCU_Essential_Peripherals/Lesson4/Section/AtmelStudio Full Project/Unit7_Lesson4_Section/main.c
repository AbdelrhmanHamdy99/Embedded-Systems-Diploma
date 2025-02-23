/*
 * Unit7_Lesson4_Section.c
 *
 * Created: 2/22/2025 5:09:40 PM
 * Author : AbdoHamdy
 */ 

#include "LCD.h"


int main(void)
{
	LCD_Config_t LCD_Config;
	LCD_Config.Display_control = Display_Control_D_On_C_On_B_On;
	LCD_Config.Entry_mode      = Entry_Mode_Inc_No_S;
	LCD_Config.function_set    = Function_Set_4bit_2line_5x8;
	LCD_Init(&LCD_Config);
	
	LCD_Write_Data("Learn-in-depth!");
    /* Replace with your application code */
    while (1) 
    {
    }
}

