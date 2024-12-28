/*
 Learn-in-depth
 Abdelrhman Hamdy
 Mastering_Embedded System online diploma */

typedef volatile unsigned int vuint32_t ;
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
// register address
/*GPIOA*/
#define GPIOA_BASE   0x40010800
#define GPIOA_CRL    *(vuint32_t *)(GPIOA_BASE + 0x00)
#define GPIOA_CRH    *(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR    *(vuint32_t *)(GPIOA_BASE + 0x0C)
/*RCC*/
#define RCC_BASE     0x40021000
#define RCC_APB2ENR  *(vuint32_t *)(RCC_BASE   + 0x18)
/*NVIC*/
#define NVIC_SER0    *(vuint32_t *)(0xE000E100) /*Irq 0 to 31 Set Enable Register*/
/*EXTI*/
#define EXTI_BASE    0x40010400
#define EXTI_IMR     *(vuint32_t *)(EXTI_BASE   + 0x00) /*External Interrupt Mask Register*/
#define EXTI_RTSR    *(vuint32_t *)(EXTI_BASE   + 0x08) /*External Interrupt Rising Trigger Selection Register*/
#define EXTI_PR      *(vuint32_t *)(EXTI_BASE   + 0x14) /*External Interrupt Pending Register*/

/*AFIO*/
#define AFIO_BASE    0x40010000
#define AFIO_EXTICR1 *(vuint32_t *)(AFIO_BASE   + 0x08)

void Clock_Init(void);
void GPIO_Init(void);

int main(void)
{
	Clock_Init();
	GPIO_Init();
	AFIO_EXTICR1 &= ~(0xF <<0); /*map EXTI0 to PA0
	                              Default value*/
	EXTI_RTSR |= (1<<0); /*Rising Trigger Enable for EXTI0*/
	EXTI_IMR |= (1<<0);  /*Enable Interrupt Request from EXTI0 to be sent to NVIC*/
	NVIC_SER0 |= (1<<6); /*Enable Interrupt on Line 6 in the NVIC which is derived by EXTI0*/
	while(1);
}

void Clock_Init(void){
	/*Clock Init*/
	RCC_APB2ENR |= (1<<2); /*GPIOA Clock Enable*/
	RCC_APB2ENR |= (1<<0); /*AFIO Clock Enable*/
}

void GPIO_Init(void){
	/*Init GPIOA*/
	/*PinA.13 as push-pull output with max output = 2MHZ*/
	GPIOA_CRH &= ~(0xF<<20);
	GPIOA_CRH |= (2 << 20);

	/*PinA.0 as floating Input */
	/*Default Value*/
	GPIOA_CRL &= ~(0b11<<0); /*PinA.0 Mode = Input*/
	/*PinA.0 Configuration = Floating Input*/
	GPIOA_CRL |= (1<<2);
	GPIOA_CRL &= ~(1<<3);
}

void EXTI0_IRQHandler(void){
	EXTI_PR |= (1<<0); /*Clear the pending interrupt to avoid infinite interrupt looping
	                     Clear by writing 1 (c_w1)*/
	GPIOA_ODR ^= 1<<13 ; /*Toggle PinA13*/
}
