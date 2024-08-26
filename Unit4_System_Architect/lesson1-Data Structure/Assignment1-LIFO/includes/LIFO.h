/*
 * LIFO.h
 *
 *  Created on: Aug 25, 2024
 *      Author: AbdoHamdy
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "Platform_types.h"

#define element_type sint32_t /*type of data carried by the LIFO*/

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

/*LIFO data type*/
typedef struct LIFO
{
    uint32_t length;    /*length of the LIFO*/
    uint32_t counter;   /*number of elements inside the LIFO at a moment*/
    element_type* base; /*pointer to first element in the LIFO*/
}LIFO_t;

typedef enum {
    LIFO_FULL,
    LIFO_EMPTY,
    LIFO_NULL,
	LIFO_LENGTH_ERROR,
    LIFO_NO_ERROR
} status_t;


/*APIs*/
status_t LIFO_create(LIFO_t*,element_type*,uint32_t);/*create a LIFO*/
status_t LIFO_push(LIFO_t*,element_type ); /*add element on top of the LIFO*/
status_t LIFO_pop (LIFO_t*,element_type*); /*remove an element from the top of the LIFO*/
status_t LIFO_top (LIFO_t*,element_type*); /*return an element that exists on the top of the LIFO without removing it*/
status_t LIFO__is_full (LIFO_t*); /*checks whether a LIFO is full or not*/
status_t LIFO__is_empty(LIFO_t*); /*checks whether a LIFO is empty or not*/
status_t LIFO_is_valid (LIFO_t*); /*make sure both lifo_ptr and its base points to a non-NUL locations*/
void LIFO_print(LIFO_t*); /*print LIFO contents from top to bottom*/


#endif /* LIFO_H_ */
