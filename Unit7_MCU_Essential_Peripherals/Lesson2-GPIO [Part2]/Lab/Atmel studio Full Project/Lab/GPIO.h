/*
 * GPIO.h
 *
 * Created: 1/20/2025 9:35:47 PM
 *  Author: AbdoHamdy
 */ 


#ifndef GPIO_H_
#define GPIO_H_
typedef volatile unsigned char vuint8_t;

#define PORTA *((vuint8_t*)0x3B)
#define DDRA  *((vuint8_t*)0x3A)
#define PINA  *((vuint8_t*)0x39)

#define PORTB *((vuint8_t*)0x38)
#define DDRB  *((vuint8_t*)0x37)
#define PINB  *((vuint8_t*)0x36)

#define PORTC *((vuint8_t*)0x35)
#define DDRC  *((vuint8_t*)0x34)
#define PINC  *((vuint8_t*)0x33)

#define PORTD *((vuint8_t*)0x32)
#define DDRD  *((vuint8_t*)0x31)
#define PIND  *((vuint8_t*)0x30)


/*define pins*/
#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

void GPIO_Init(void);




#endif /* GPIO_H_ */