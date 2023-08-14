/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdelrhman Hamdy Zakaria
 * @controller     : STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
**/
#include "Platform_Types.h"

#define RCC_BASE_ADDRESS      0x40021000
#define PORTA_BASE_ADDRESS    0x40010800

#define RCC_APB2ENR           *(vuint32*)(RCC_BASE_ADDRESS + 0x18)
#define GPIOA_CRH             *(vuint32*)(PORTA_BASE_ADDRESS + 0x04)
#define GPIOA_ODR             *(vuint32*)(PORTA_BASE_ADDRESS + 0x0C)

#define GPIOA_PIN13           (1<<13)
int main(void)
{
	RCC_APB2ENR |= (1<<2);/*set bit2*/
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;

    while(1){
    	GPIOA_ODR ^= GPIOA_PIN13;
    	for(uint32 i = 0 ; i < 100000; i++);
    }
}
