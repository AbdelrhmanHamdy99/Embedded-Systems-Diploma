/*
 * stm32f103x6.h
 *
 *  Created on: Feb 4, 2025
 *      Author: AbdoHamdy
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

/******************************************************************
							Includes
******************************************************************/
#include <stdint.h>

/*================================================================================================================*/

/***************************************************************
			Base addresses for Memories
****************************************************************/
#define FLASH_MEMORY_BASE   					0x08000000
#define SYSTEM MEMORY_BASE	  				0x1FFFF000
#define OPTION BYTES_BASE   					0x1FFFF800
#define SRAM_BASE   	    					0x20000000
#define PERIPHERALS_BASE   					0x40000000
#define Cortex_M3_Internal_Peripherals_BASE   			0xE0000000

/*================================================================================================================*/

/***************************************************************
			Base addresses for BUS Peripherals
****************************************************************/

/**********************AHB BUS Peripherals**********************/
#define RCC_BASE   	    				    	0x40021000 		/*Reset and clock control RCC Base Address*/
/**********************APB2 BUS Peripherals*********************/
#define GPIOD_BASE   	    				   	0x40011400		/*GPIO Port D Base Address*/
#define GPIOC_BASE   	    				   	0x40011000		/*GPIO Port C Base Address*/
#define GPIOB_BASE   	    				   	0x40010C00		/*GPIO Port B Base Address*/
#define GPIOA_BASE   	    				   	0x40010800		/*GPIO Port A Base Address*/

#define EXTI_BASE   	    				   	0x40010400		/*External Interrupt Base Address*/

#define AFIO_BASE   	    				   	0x40010000		/*Alternate Function Input/Output Base Address*/
/**********************APB1 BUS Peripherals*********************/

/*================================================================================================================*/

/***************************************************************
					Peripheral register
****************************************************************/

/*****************AHB BUS Peripherals Registers****************/
/************************RCC Registers************************/
typedef struct {
	volatile uint32_t CR      ;
	volatile uint32_t CFGR    ;
	volatile uint32_t CIR     ;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR  ;
	volatile uint32_t APB2ENR ;
	volatile uint32_t APB1ENR ;
	volatile uint32_t BDCR    ;
	volatile uint32_t CSR     ;
}RCC_T;

/****************APB2 BUS Peripherals Registers*****************/
/************************GPIO Registers************************/
typedef struct {
	volatile uint32_t CRL ;
	volatile uint32_t CRH ;
	volatile uint32_t IDR ;
	volatile uint32_t ODR ;
	volatile uint32_t BSRR;
	volatile uint32_t BRR ;
	volatile uint32_t LCKR;
}GPIO_T;

/************************AFIO Registers************************/
typedef struct {
	volatile uint32_t EVCR     ;
	volatile uint32_t MAPR     ;
	volatile uint32_t EXTICR1  ;
	volatile uint32_t EXTICR2  ;
	volatile uint32_t EXTICR3  ;
	volatile uint32_t EXTICR4  ;
	const    uint32_t RESERVED0;
	volatile uint32_t MAPR2;
}AFIO_T;

/************************EXTI Registers************************/
typedef struct {
	volatile uint32_t IMR  ;
	volatile uint32_t EMR  ;
	volatile uint32_t RTSR ;
	volatile uint32_t FTSR ;
	volatile uint32_t SWIER;
	volatile uint32_t PR   ;
}EXTI_T;

/****************APB1 BUS Peripherals Registers*****************/

/*================================================================================================================*/

/*************************************************************
					Peripheral Instants
**************************************************************/

/*****************AHB BUS Peripherals Instants****************/
/************************RCC Instants*************************/
#define RCC    ((RCC_T*)(RCC_BASE))

/*****************APB2 BUS Peripherals Instants**************/
/***********************GPIO Instants************************/
#define GPIOA  ((GPIO_T*)(GPIOA_BASE))
#define GPIOB  ((GPIO_T*)(GPIOB_BASE))
#define GPIOC  ((GPIO_T*)(GPIOC_BASE))
#define GPIOD  ((GPIO_T*)(GPIOD_BASE))

/**********************AFIO Instants************************/
#define AFIO   ((AFIO_T*)(AFIO_BASE))

/**********************EXTI Instants***********************/
#define EXTI   ((EXTI_T*)(EXTI_BASE))

/*****************APB1 BUS Peripherals Instants*************/

/*================================================================================================================*/

/***************************************************************
					clock enable Macros
****************************************************************/
/*****************AHB Peripherals clock enable*****************/

/****************APB2 Peripherals clock enable****************/
#define AFIO_Clock_Enable  (RCC->APB2ENR |= (1<<0))
#define GPIOA_Clock_Enable (RCC->APB2ENR |= (1<<2))
#define GPIOB_Clock_Enable (RCC->APB2ENR |= (1<<3))
#define GPIOC_Clock_Enable (RCC->APB2ENR |= (1<<4))
#define GPIOD_Clock_Enable (RCC->APB2ENR |= (1<<5))

/****************APB1 Peripherals clock enable****************/

/*================================================================================================================*/


#endif /* INC_STM32F103X6_H_ */
