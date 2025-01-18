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


#endif /* MEMMAP_H_ */