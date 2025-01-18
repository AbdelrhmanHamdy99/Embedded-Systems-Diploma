/*
 * MemMap.h
 *
 * Created: 1/13/2025 10:32:19 PM
 *  Author: AbdoHamdy
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_

typedef volatile unsigned char vuint8_t;

#define n_bins 8 /*number of pins per port*/
/*DIO*/
/*PORTA*/
#define PORTA  *((vuint8_t *)0x3B) 
#define DDRA   *((vuint8_t *)0x3A)
#define PINA   *((vuint8_t *)0x39)

/*PORTC*/
#define PORTC  *((vuint8_t *)0x35)
#define DDRC   *((vuint8_t *)0x34)
#define PINC   *((vuint8_t *)0x33)
/*PORTD*/
#define PORTD  *((vuint8_t *)0x32)
#define DDRD   *((vuint8_t *)0x31)
#define PIND   *((vuint8_t *)0x30)



#endif /* MEMMAP_H_ */