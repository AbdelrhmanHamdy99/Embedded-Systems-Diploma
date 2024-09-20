/*
 * FIFO.c
 *
 *  Created on: Aug 25, 2024
 *      Author: AbdoHamdy
 */

#include "FIFO.h"
#include "Platform_types.h"
#include <stdio.h>

status_t FIFO_create(FIFO_t* FIFO_ptr,element_type* first_ele_ptr,uint32_t length){
	/*check that both FIFO object, and FIFO storage location are not null*/
	if(!FIFO_ptr || !first_ele_ptr)
		return FIFO_NULL;
	/*length cannot be a negative number. So, it cannot be less than zero. But if the user 
	entered a negative length it will be converted to a positive one using 2's complement
	causing a logical error. However it was his fault*/
	if(!length)
		return FIFO_LENGTH_ERROR;

	/*safely create a FIFO*/
	FIFO_ptr->base = first_ele_ptr;
	FIFO_ptr->head = first_ele_ptr;
	FIFO_ptr->tail = first_ele_ptr;
	FIFO_ptr->length = length;
	FIFO_ptr->counter = 0; /*no element in the FIFO*/

	return FIFO_NO_ERROR; /*creation is done successfully*/
}

status_t FIFO_enqueue(FIFO_t* FIFO_ptr,element_type data){
	switch (FIFO__is_full(FIFO_ptr))
	{
	case FIFO_NULL: /*either FIFO_ptr, or its base is not a valid pointers*/
		return FIFO_NULL;
	case FIFO_FULL: /*FIFO is full*/
		return FIFO_FULL;
	case FIFO_LENGTH_ERROR: /*FIFO is full*/
		return FIFO_LENGTH_ERROR;
	case FIFO_NO_ERROR:
		/*enqueue the element and advance the tail to point to the next empty location*/
		*(FIFO_ptr->tail++) = data; 
		FIFO_ptr->counter++; /*increase number of elements inside the queue*/

		/*check if the tail points to an address outside the FIFO address space*/
		if(FIFO_ptr->tail == FIFO_ptr->base + FIFO_ptr->length)
			FIFO_ptr->tail = FIFO_ptr->base; /*circular FIFO*/
		break;
	default : /*not handled error*/
		return FIFO__is_full(FIFO_ptr);
	}
	return FIFO_NO_ERROR; /*element enqueued successfully*/
}

status_t FIFO_dequeue (FIFO_t* FIFO_ptr,element_type *out){
	switch (FIFO__is_empty(FIFO_ptr))
	{
	case FIFO_NULL: /*either FIFO_ptr, or its base is not a valid pointers*/
		return FIFO_NULL;
	case FIFO_EMPTY: /*FIFO is empty*/
		return FIFO_EMPTY;
	case FIFO_LENGTH_ERROR: /*FIFO is empty*/
		return FIFO_LENGTH_ERROR;
	case FIFO_NO_ERROR:
		/*dequeue the element and advance the head to point to the next location*/
		*out = *(FIFO_ptr->head++);
		FIFO_ptr->counter--; /*decrease number of elements inside the queue by one*/

		/*check if the head points to an address outside the FIFO address space*/
		if(FIFO_ptr->head == FIFO_ptr->base + FIFO_ptr->length)
			FIFO_ptr->head = FIFO_ptr->base; /*circular FIFO*/
		break;
	default : /*not handled error*/
		return FIFO__is_empty(FIFO_ptr);
	}
	return FIFO_NO_ERROR; /*element dequeued successfully*/
}

status_t FIFO__is_full(FIFO_t* FIFO_ptr){
	/*check that both FIFO_ptr, and its base are valid pointers*/
	if(FIFO_is_invalid(FIFO_ptr) != FIFO_NO_ERROR)
		return FIFO_is_invalid(FIFO_ptr);
	/*check if whether number of elements stored in the stack
	reached the max available length*/
	if(FIFO_ptr->counter == FIFO_ptr->length)
		return FIFO_FULL;
	return FIFO_NO_ERROR;
}

status_t FIFO__is_empty(FIFO_t* FIFO_ptr){
	/*check that both FIFO_ptr, and its base are valid pointers*/
	if(FIFO_is_invalid(FIFO_ptr) != FIFO_NO_ERROR)
		return FIFO_is_invalid(FIFO_ptr);
	/*check if there is no elements in the FIFO*/
	if(!FIFO_ptr->counter)
		return FIFO_EMPTY;
	return FIFO_NO_ERROR;
}

status_t FIFO_is_invalid (FIFO_t* FIFO_ptr){
	/*make sure both FIFO_ptr and its base points to a non-NUL locations*/
	if(!FIFO_ptr || !FIFO_ptr->base)
		return FIFO_NULL;
	if(!FIFO_ptr->length)
		return FIFO_LENGTH_ERROR;
	return FIFO_NO_ERROR;
}

void FIFO_print(FIFO_t* FIFO_ptr){
	element_type* temp;
	uint32_t i; /*counter*/
	printf("\n===========print FIFO contents from top to bottom===========\n");
	
	switch (FIFO__is_empty(FIFO_ptr))
	{
	case FIFO_NULL:
		printf("ERROR!! FIFO is not valid\n");
		break;
	case FIFO_EMPTY:
		printf("the FIFO is Empty\n");
		break;
	case FIFO_LENGTH_ERROR:
		printf("FIFO Length cannot be zero\n");
		break;
	case FIFO_NO_ERROR:
		temp = FIFO_ptr->head;
		i = FIFO_ptr->counter;
		while (i--)
		{
			if(temp == FIFO_ptr->base + FIFO_ptr->length)
				temp = FIFO_ptr->base;
			printf(format_specifier,*temp++);
			printf("\n");
		}
		break;
	default: /*unknown error*/
		printf("Unknown Error!!");
		break;
	}
	printf("============================================================\n\n");
}
