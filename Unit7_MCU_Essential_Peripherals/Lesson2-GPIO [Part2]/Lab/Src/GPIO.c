/*
 * GPIO.c
 *
 * Created: 1/20/2025 10:54:38 PM
 *  Author: AbdoHamdy
 */ 
#include "GPIO.h"

void GPIO_Init(void){
	/*PortC as output*/
	DDRA = 0xFF;
	/*PortD as output*/
	DDRB = 0xFF;
}
