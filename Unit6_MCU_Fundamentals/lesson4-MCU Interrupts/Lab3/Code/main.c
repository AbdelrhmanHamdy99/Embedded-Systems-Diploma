/*
 * Test2.c
 *
 * Created: 1/2/2025 8:23:35 AM
 * Author : AbdoHamdy
 */ 

#define F_CPU  1000000UL

#include <avr/interrupt.h>
#include <util/delay.h>

typedef volatile unsigned char vuint8_t ;

#define SET_BIT(port,pin)    port |=  (1 << pin);
#define RESET_BIT(port,pin)  port &= ~(1 << pin);
#define TOGGLE_BIT(port,pin) port ^=  (1 << pin);

#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7
#define I_BIT  7

#define IO_BASE 0x20
/*registers addresses*/
#define SREG   *(vuint8_t *)(IO_BASE+0x3F)
#define GICR   *(vuint8_t *)(IO_BASE+0x3B)
#define MCUCR  *(vuint8_t *)(IO_BASE+0x35)
#define MCUCSR *(vuint8_t *)(IO_BASE+0x34)
#define PORTD  *(vuint8_t *)(IO_BASE+0x12)
#define DDRD   *(vuint8_t *)(IO_BASE+0x11)


void EXTI_Init(void);
void GPIO_Init(void);

int main(void)
{
	GPIO_Init();
	EXTI_Init();
	while (1) 
    {
		/*make sure that all PINs are output LOW*/
		RESET_BIT(PORTD, PIN5);  /*write 0 on PORTD PIN5*/
		RESET_BIT(PORTD, PIN6);  /*write 0 on PORTD PIN6*/
		RESET_BIT(PORTD, PIN7);  /*write 0 on PORTD PIN7*/
    }
}

void EXTI_Init(void){
	/*Interrupts Configuration*/
	/*1. INT0*/
	/*Any logical change on INT0 generates an interrupt request*/
	SET_BIT(MCUCR , 0);
	RESET_BIT(MCUCR , 1);
	/*2. INT1*/
	/*The rising edge of INT1 generates an interrupt request*/
	SET_BIT(MCUCR , 2);
	SET_BIT(MCUCR , 3);
	
	/*3. INT2*/
	/*The failing edge of INT1 generates an interrupt request*/
	RESET_BIT(MCUCSR , 6);
	/*enable Interrupts*/
	SET_BIT(SREG, I_BIT); /*SREG-I enable
 	                        enable Global Interrupts*/
	SET_BIT(GICR, PIN5);  /*enable INT0 mask*/
	SET_BIT(GICR, PIN6);  /*enable INT1 mask*/
	SET_BIT(GICR, PIN7);  /*enable INT2 mask*/
}
void GPIO_Init(void){
	/*PortD pins(5,6,7) as output*/
	SET_BIT(DDRD, PIN5);  /*D5 as output*/
	SET_BIT(DDRD, PIN6);  /*D6 as output*/
	SET_BIT(DDRD, PIN7);  /*D7 as output*/
}
/*Interrupt handler for External Interrupt0(INT0)*/
ISR(INT0_vect){
	SET_BIT(PORTD, PIN5);  /*write 1 on PORTD PIN5*/
	_delay_ms(1000); /*wait for a while to observe the change*/
}
/*Interrupt handler for External Interrupt1(INT1)*/
ISR(INT1_vect){
	SET_BIT(PORTD, PIN6);  /*write 1 on PORTD PIN6*/
	_delay_ms(1000); /*wait for a while to observe the change*/
}
/*Interrupt handler for External Interrupt2(INT2)*/
ISR(INT2_vect){
	SET_BIT(PORTD, PIN7);  /*write 1 on PORTD PIN7*/
	_delay_ms(1000); /*wait for a while to observe the change*/
}