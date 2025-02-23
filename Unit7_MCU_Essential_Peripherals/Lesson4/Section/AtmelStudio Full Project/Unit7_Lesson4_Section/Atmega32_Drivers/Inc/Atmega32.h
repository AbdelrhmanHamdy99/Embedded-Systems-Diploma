/*
 * Atmega32.h
 *
 * Created: 2/22/2025 5:17:57 PM
 *  Author: AbdoHamdy
 */ 


#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#include <stdint.h>
/****************************************************************
 *				 Bus Peripherals Base Addresses					*
 ****************************************************************/
#define DIOA_BASE				0x39
#define DIOB_BASE				0x36
#define DIOC_BASE				0x33
#define DIOD_BASE				0x30

/****************************************************************
 *				Bus Peripherals Register Types					*
 ****************************************************************/
typedef struct {
	volatile uint8_t PIN;
	volatile uint8_t DDR;
	volatile uint8_t PORT;
	}DIO_T;
/****************************************************************
 *						Peripheral Instants						*
 ****************************************************************/
#define DIOA				((DIO_T*)DIOA_BASE)
#define DIOB				((DIO_T*)DIOB_BASE)
#define DIOC				((DIO_T*)DIOC_BASE)
#define DIOD				((DIO_T*)DIOD_BASE)
#endif /* ATMEGA32_H_ */