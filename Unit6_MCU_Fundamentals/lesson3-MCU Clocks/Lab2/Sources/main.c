/*
 Learn-in-depth
 Abdelrhman Hamdy
 Mastering_Embedded System online diploma */

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
#define GPIOA_BASE 0x40010800
#define RCC_BASE    0x40021000

#define GPIOA_CRH   *(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR   *(vuint32_t *)(GPIOA_BASE + 0x0C)
#define RCC_CR      *(vuint32_t *)(RCC_BASE   + 0x00)
#define RCC_CFGR    *(vuint32_t *)(RCC_BASE   + 0x04)
#define RCC_APB2ENR *(vuint32_t *)(RCC_BASE   + 0x18)

int main(void)
{
	/*Clock Init*/
	RCC_CR |= 1<<0; /*HSION
	                  Internal High-Speed Clock enable
		          default value*/

	RCC_CFGR &= ~(0b11); /*SYSCLK = HSI = 8MHZ
                               Default value*/

	RCC_CFGR &= ~(1 << 7); /*AHB Prescaler = 1
	                         HCLK = SYSCLK = 8MHZ
			         Default value*/
	
	RCC_CFGR &= ~(0b111 << 8);
	RCC_CFGR |= 0b100 << 8; /*APB1 Prescaler = 2
                                  PCLK2 = HCLK / 2 = 4 MHZ*/
	
	RCC_CFGR &= ~(0b111 << 11);
	RCC_CFGR |= 0b101 << 11; /*APB2 Prescaler = 4
	                           pclk2 = HCLK / 4 = 2 MHZ*/

	while(!(RCC_CR & (1 << 1))); /*HSIRDY
	                               wait untill internal 8 MHZ RC oscillator ready*/

	RCC_APB2ENR |= (1<<2); /*GPIOA_Clock Enable*/

	//Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;
	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}

