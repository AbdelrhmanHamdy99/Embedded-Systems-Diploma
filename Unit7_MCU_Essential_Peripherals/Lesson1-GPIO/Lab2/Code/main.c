/*
 * Unit7_section1_assignment1.c
 *
 * Created: 1/13/2025 10:30:38 PM
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
    while (1) 
    {
		uint8_t i = 0;
		while(i < n_bins)
		{
			SET_BIT(PORTA, i++);
			_delay_ms(500);
		}
		while (i)
		{
			RESET_BIT(PORTA, --i);
			_delay_ms(500);
		}
    }
}

void DIO_Init(void){
	DDRA =0xFF; /*Mark PORTA direction as output*/
}