/*
 * FIFO.h
 *
 *  Created on: Aug 25, 2024
 *      Author: AbdoHamdy
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "Platform_types.h"

#define element_type sint32_t /*type of data carried by the FIFO*/

/*format specifier used with each data type*/
#if   (element_type == sint32_t)
    #define format_specifier "%d"
#elif (element_type == uint32_t)
    #define format_specifier "%u"
#elif (element_type == sint16_t)
    #define format_specifier "%hd"
#elif (element_type == uint16_t)
    #define format_specifier "%hu"   
#elif (element_type == sint8_t || element_type == uint8_t)
    #define format_specifier "%c"
#elif (element_type == f32_t)
    #define format_specifier "%f"
#elif (element_type == f64_t)
    #define format_specifier "%lf"
#endif

/*FIFO data type*/
typedef struct FIFO
{
    uint32_t length;     /*length  of the FIFO*/
    uint32_t counter;    /*number  of elements inside the FIFO at a moment*/
    element_type* base;  /*pointer to the base address of the FIFO*/
    element_type* head;  /*pointer to first element in the FIFO*/
    element_type* tail;  /*pointer to last element in the FIFO*/
}FIFO_t;

typedef enum {
    FIFO_FULL,
    FIFO_EMPTY,
    FIFO_NULL,
	FIFO_LENGTH_ERROR,
    FIFO_NO_ERROR
} status_t;


/*APIs*/
status_t FIFO_create (FIFO_t*,element_type*,uint32_t);/*create a FIFO*/
status_t FIFO_enqueue(FIFO_t*,element_type ); /*add element on top of the FIFO*/
status_t FIFO_dequeue(FIFO_t*,element_type*); /*remove an element from the base of the FIFO*/
status_t FIFO__is_full (FIFO_t*); /*checks whether a FIFO is full or not*/
status_t FIFO__is_empty(FIFO_t*); /*checks whether a FIFO is empty or not*/
status_t FIFO_is_invalid (FIFO_t*); /*make sure both FIFO_ptr, its base, and end pointers point to non-NUL locations*/
void FIFO_print(FIFO_t*); /*print FIFO contents */


#endif /* FIFO_H_ */
