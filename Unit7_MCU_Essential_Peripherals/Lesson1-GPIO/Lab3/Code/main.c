/*
 * Unit7_Lesson1_Lab3.c
 *
 * Created: 1/15/2025 12:01:05 AM
 * Author : AbdoHamdy
 */ 

#define  F_CPU 8000000
#include "MemMap.h"
#include "Utils.h"
#include <util/delay.h>

void DIO_Init(void);

int main(void)
{
    DIO_Init();
	unsigned char i = 0; 
    unsigned char flag = 0;
	 
	while (1) 
    {
		/*Push button is pressed*/
		if(!READ_BIT(PINC,0)){
			if(!flag){
				_delay_ms(20); /*for debouncing "Most mechanical switches bounce for 5–20 ms"*/
				if(!READ_BIT(PINC,0)){ /*Make sure the button is still pressed*/
					SET_BIT(PORTA,i); /*Turn on led(i)*/
					RESET_BIT(PORTA,(i-1U) % n_bins); /*Turn on led(i-1)*/
					i = (i + 1) % n_bins;
					flag = 1;	
				}	
			}
		}else{
			flag = 0;
		}
		_delay_ms(5);
    }
}

void DIO_Init(void){
	DDRA=0xFF; /*Port A as output*/
	/*Configure Port C pin0 as input with pull-up resistor*/
	RESET_BIT(DDRC, 0); /*Port C pin0 as input*/
	SET_BIT(PORTC,0); /*enable pull-up resistor for Port C pin0*/
}
