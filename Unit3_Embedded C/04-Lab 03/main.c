#include "platform_types.h"

#define SYSCTL_BASE     0x400FE000
#define SYSCTL_RCGC2_R  *((vuint32_t*) (SYSCTL_BASE + 0x108))
#define GPIO_PORTF_BASE 0x40025000
typedef union {
	vuint32_t port;
	struct {
		vuint32_t pin0 : 1;
		vuint32_t pin1 : 1;
		vuint32_t pin2 : 1;
		vuint32_t pin3 : 1;
		vuint32_t pin4 : 1;
		vuint32_t pin5 : 1;
		vuint32_t pin6 : 1;
		vuint32_t pin7 : 1;
		vuint32_t pin8 : 1;
		vuint32_t pin9 : 1;
		vuint32_t pin10: 1;
		vuint32_t pin11: 1;
		vuint32_t pin12: 1;
		vuint32_t pin13: 1;
		vuint32_t pin14: 1;
		vuint32_t pin15: 1;
		vuint32_t pin16: 1;
		vuint32_t pin17: 1;
		vuint32_t pin18: 1;
		vuint32_t pin19: 1;
		vuint32_t pin20: 1;
		vuint32_t pin21: 1;
		vuint32_t pin22: 1;
		vuint32_t pin23: 1;
		vuint32_t pin24: 1;
		vuint32_t pin25: 1;
		vuint32_t pin26: 1;
		vuint32_t pin27: 1;
		vuint32_t pin28: 1;
		vuint32_t pin29: 1;
		vuint32_t pin30: 1;
		vuint32_t pin31: 1;
	}pins;
} GPIO_PORTF_RU;

GPIO_PORTF_RU* GPIO_PORTF_DATA_R= (GPIO_PORTF_RU*) (GPIO_PORTF_BASE + 0x3FC);
GPIO_PORTF_RU* GPIO_PORTF_DIR_R = (GPIO_PORTF_RU*) (GPIO_PORTF_BASE + 0x400);
GPIO_PORTF_RU* GPIO_PORTF_DEN_R = (GPIO_PORTF_RU*) (GPIO_PORTF_BASE + 0x51C);


int main(void){
	/*initialization*/
	SYSCTL_RCGC2_R = 0x20; /*Enable the clock for gpio*/
	vuint32_t i;
	/*delay to make sure gpiof is up and running 
	before accessing it's registers*/
	for(i = 0; i < 200 ; i++); 
	
	GPIO_PORTF_DIR_R->pins.pin3 = 1; /*mark portf pin3 as an output pin*/
	GPIO_PORTF_DEN_R->pins.pin3 = 1; /*mark portf pin3 as a digital pin*/
	
	/*toggle the led*/
	while(1){
		GPIO_PORTF_DATA_R->pins.pin3 = 1; /*led on*/
		for(i = 0; i < 10000; i++); /*software delay*/
		GPIO_PORTF_DATA_R->pins.pin3 = 0; /*led off*/
		for(i = 0; i < 10000; i++); /*software delay*/
	}
	return 0;
}