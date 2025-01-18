/*
 * Unit7_Section1_lab3.c
 *
 * Created: 1/15/2025 10:33:05 AM
 * Author : AbdoHamdy
 */ 
#define F_CPU 8000000U
#include "MemMap.h"
#include "Utils.h"
#include <util/delay.h>

void DIO_Init(void);

unsigned char static seven_segment[] = {0x3F, 0x06, 0x5B, 0x4F,0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
int main(void)
{
	DIO_Init();
	unsigned char i = 0;
	while (1) 
    {
		PORTD = seven_segment[i];
		i = (i + 1) % 10; /*update i*/
		_delay_ms(1000);
    }
}
void DIO_Init(void){
	DDRD = 0xFF; /*PORTD as output*/
}

