/*
 * unit7_Section1_lab4.c
 *
 * Created: 1/15/2025 9:08:55 PM
 * Author : AbdoHamdy
 */ 

#define F_CPU 8000000U

#include "MemMap.h"
#include "Utils.h"
#include <util/delay.h>

void DIO_Init(void);

int main(void)
{
	unsigned char n1 = 0, n2 = 0;
	unsigned short counter = 0;
    DIO_Init();
	while (1) 
    {
		/*display the tens digit*/
		RESET_BIT(PORTD,4); /*1. disable the units 7-Segment*/
		PORTD &= ~0xF;      /*2. remove the units digit*/
		PORTD |= n2;        /*3. type the tens digit*/
		SET_BIT(PORTD,5);   /*4. enable the tens 7-Segment*/
		
		_delay_ms(10);      /*delay during multiplexing to balance flicker-free operation and smooth transitions.*/
		
		/*display the units digit*/
		RESET_BIT(PORTD,5); /*1. disable the tens 7-segment*/
		PORTD &= ~0xF;      /*2. remove the tens digit*/
		PORTD |= n1;        /*3. type the units digit*/
		SET_BIT(PORTD,4);   /*4. enable the units 7-Segment*/

		_delay_ms(10);      /*delay during multiplexing to balance flicker-free operation and smooth transitions.*/
		
		/*to keep the numbers on the screen for 1 second*/
		counter++;
		if(counter == 50 ){ /*1Second*/
			counter = 0;
			n1 = (n1 + 1) % 10;
			if(n1 == 0){
				n2 = (n2+1) %10;
			}
		}
    }
}

void DIO_Init(void){
	DDRD = 0xFF; /*PortD as output*/
}
