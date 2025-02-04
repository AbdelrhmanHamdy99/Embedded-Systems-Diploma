/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "Platform_types.h"

#define SET_BIT(REG,BIT)    REG |=  (1<<BIT)
#define RESET_BIT(REG,BIT)  REG &= ~(1<<BIT)
#define TOGGLE_BIT(REG,BIT) REG ^=  (1<<BIT)
#define READ_BIT(REG,BIT)   ((REG & (1<<BIT)) >> BIT)
/*Peripherals base addresses*/
#define RCC_BASE   0x40021000
#define GPIOA_BASE 0x40010800
#define GPIOB_BASE 0x40010C00

/*Required registers*/
/*RCC*/
#define RCC_APB2ENR  *((vuint32_t*)(RCC_BASE + 0x18))
/*GPIOA*/
#define GPIOA_CRL    (*(vuint32_t*)(GPIOA_BASE + 0x0))
#define GPIOA_CRH    (*(vuint32_t*)(GPIOA_BASE + 0x4))
#define GPIOA_IDR    (*(vuint32_t*)(GPIOA_BASE + 0x8))
/*GPIOB*/
#define GPIOB_CRL    (*(vuint32_t*)(GPIOB_BASE + 0x0))
#define GPIOB_CRH    (*(vuint32_t*)(GPIOB_BASE + 0x4))
#define GPIOB_ODR    (*(vuint32_t*)(GPIOB_BASE + 0xC))

void GPIO_Init(void);
void Clock_Init(void);
int main(void)
{
	Clock_Init();
	GPIO_Init();
	uint8_t flag1 = 0;
	/* Loop forever */
	for(;;){
		/*We Want to avoid starvation*/
		/*SW1 at PA1 pressed*/
		if(!READ_BIT(GPIOA_IDR,1) && !flag1){
			/*Toggle led on portB1*/
			TOGGLE_BIT(GPIOB_ODR,1);
			/*Single Pressing*/
			flag1 = 1;
		}
		/*SW2 at PA13 pressed*/
		/*Multi Pressing*/
		if(READ_BIT(GPIOA_IDR,13)){
			/*Toggle led on portB13*/
			TOGGLE_BIT(GPIOB_ODR,13);
		}
		if(READ_BIT(GPIOA_IDR,1)){
			flag1 = 0;
		}
		for(uint32_t i = 0; i < 20000; i++); /*delay to observe changes*/
	}
}
void GPIO_Init(void){
	/*Configure PORTA PIN1 as floating input pin*/
	/*Which is the default reset value*/
	/*1. mode = 00 = input*/
	RESET_BIT(GPIOA_CRL,4);
	RESET_BIT(GPIOA_CRL,5);
	/*2. CNF = 01 = Floating input*/
	SET_BIT(GPIOA_CRL,6);
	RESET_BIT(GPIOA_CRL,7);

	/*Configure PORTA PIN13 as floating input pin*/
	/*Which is the default reset value*/
	/*1. mode = 00 = input*/
	RESET_BIT(GPIOA_CRH,20);
	RESET_BIT(GPIOA_CRH,21);
	/*2. CNF = 01 = Floating input*/
	SET_BIT(GPIOA_CRH,22);
	RESET_BIT(GPIOA_CRH,23);

	/*Configure PORTB PIN1 as Push-Pull output pin*/
	/*1. mode = 01 (output with maximum frequency = 10MHZ)*/
	SET_BIT(GPIOB_CRL,4);
	RESET_BIT(GPIOB_CRL,5);
	/*2. CNF = 00 = Push-Pull output*/
	RESET_BIT(GPIOB_CRL,6);
	RESET_BIT(GPIOB_CRL,7);

	/*Configure PORTB PIN13 as Push-Pull output pin*/
	/*1. mode = 01 (output with maximum frequency = 10MHZ)*/
	SET_BIT(GPIOB_CRH,20);
	RESET_BIT(GPIOB_CRH,21);
	/*2. CNF = 00 = Push-Pull output*/
	RESET_BIT(GPIOB_CRH,22);
	RESET_BIT(GPIOB_CRH,23);
}
void Clock_Init(void){
	/*enable clock for ports A and B*/
	SET_BIT(RCC_APB2ENR,2); /*enable GPIOA clock*/
	SET_BIT(RCC_APB2ENR,3); /*enable GPIOB clock*/
}
