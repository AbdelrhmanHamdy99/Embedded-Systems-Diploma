/*
 * Lab.c
 *
 * Created: 1/20/2025 9:11:37 PM
 * Author : AbdoHamdy
 */ 

#define F_CPU 1000000U
#include <util/delay.h>
#include "LCD.h"
#include "GPIO.h"
#include "KeyPad.h"

int main(void)
{
	LCD_Init();
	keyPad_Init();
    while (1) 
    {	
		char c = KeyPad_GetKeyPressed();
		if(c == ' '){
			/*Clear Screen*/
			LCD_Write_Command(LCD_Clear);
			LCD_Write_Command(LCD_Return_Home);
		}else if(c == 0){
			/*do nothing no character is pressed*/
		}else{
			LCD_SendCharacter(c);
		}
    }
}

