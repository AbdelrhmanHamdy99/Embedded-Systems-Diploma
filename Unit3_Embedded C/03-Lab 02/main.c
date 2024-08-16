/*
main.c
by: Abdelrhman Hamdy
*/
#include "platform_types.h"

#define RCC_BASE        0x40021000
#define GPIO_PORTA_BASE 0x40010800

typedef union{
	vuint32_t port;
	struct {
		vuint32_t reserved : 13;
		vuint32_t pin13 : 1;
	}pins;
}gpio_portx_ODR_U;

#define RCC_APB2ENR_R   *((vuint32_t *) (RCC_BASE + 0x18))
#define GPIO_PORTA_CRH  *((vuint32_t *) (GPIO_PORTA_BASE + 0x04))
gpio_portx_ODR_U* GPIO_PORTA_ODR_R = (gpio_portx_ODR_U*) (GPIO_PORTA_BASE + 0x0C);
/*variables for debugging purposes */
uint8_t gi_test[5] = {1,2}; /*global initialized */
uint8_t gu_test[5];        /*global uninitialized*/
uint8_t const c_test[5];  /*const*/


int main(void)
{
	/*initialization*/
	RCC_APB2ENR_R  |=  (1<<2);           /*set bit2*/
	GPIO_PORTA_CRH &= ~(0xf << 20);      /*reset bits 20-->24*/
	GPIO_PORTA_CRH |=  (2 << 20);        /*write 2 on bits 20-->24*/
	/*toggle a led*/
	uint32_t i;
	for(;;){
		GPIO_PORTA_ODR_R->pins.pin13 = 1;/*led off*/
		for(i = 0 ; i < 100000; i++);    /*busy waiting*/
		GPIO_PORTA_ODR_R->pins.pin13 = 0;/*led on*/
		for(i = 0 ; i < 100000; i++);    /*busy waiting*/
	}
}
