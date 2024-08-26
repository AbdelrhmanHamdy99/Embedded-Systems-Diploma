/*
 * LIFO.c
 *
 *  Created on: Aug 25, 2024
 *      Author: AbdoHamdy
 */

#include "LIFO.h"
#include "Platform_types.h"
#include <stdio.h>

status_t LIFO_create(LIFO_t* lifo_ptr,element_type* first_ele_ptr,uint32_t length){
	/*check that both lifo_ptr, and first_ele_ptr are valid pointers*/
	if(!lifo_ptr || !first_ele_ptr)
		return LIFO_NULL;
	/*length cannot be a negative number. So, it cannot be less than zero. But if the user 
	entered a negative length it will be converted to a positive one using 2's complement
	causing a logical error. However it was his fault*/
	if(length == 0)
		return LIFO_LENGTH_ERROR;

	/*safely create a LIFO*/
	lifo_ptr->base = first_ele_ptr;
	lifo_ptr->length = length;
	lifo_ptr->counter = 0; /*no element pushed yet*/

	return LIFO_NO_ERROR; /*creation is done successfully*/
}

status_t LIFO_push(LIFO_t* lifo_ptr,element_type data){
	switch (LIFO__is_full(lifo_ptr))
	{
	case LIFO_NULL: /*either lifo_ptr, or its base is not a valid pointers*/
		return LIFO_NULL;
	case LIFO_FULL: /*LIFO is full*/
		return LIFO_FULL;
	default:
		lifo_ptr->base[lifo_ptr->counter++] = data; /*safely push the element on the top of the LIFO*/
		break;
	}
	return LIFO_NO_ERROR; /*element pushed successfully*/
}

status_t LIFO_pop (LIFO_t* lifo_ptr,element_type *out){
	switch (LIFO__is_empty(lifo_ptr))
	{
	case LIFO_NULL: /*either lifo_ptr, or its base is not a valid pointers*/
		return LIFO_NULL;
	case LIFO_EMPTY: /*LIFO is empty*/
		return LIFO_EMPTY;
	default:
		*out = lifo_ptr->base[--(lifo_ptr->counter)];
		break;
	}
	return LIFO_NO_ERROR; /*element pushed successfully*/
}

status_t LIFO_top (LIFO_t* lifo_ptr,element_type *out){
	switch (LIFO__is_empty(lifo_ptr))
	{
	case LIFO_NULL: /*either lifo_ptr, or its base is not a valid pointers*/
		return LIFO_NULL;
	case LIFO_EMPTY: /*LIFO is empty*/
		return LIFO_EMPTY;
	default:
		*out = lifo_ptr->base[lifo_ptr->counter - 1];
		break;
	}
	return LIFO_NO_ERROR; /*element pushed successfully*/
}

status_t LIFO__is_full(LIFO_t* lifo_ptr){
	/*check that both lifo_ptr, and its base are valid pointers*/
	if(LIFO_is_valid(lifo_ptr) == LIFO_NULL)
		return LIFO_NULL;
	/*check if whether number of elements stored in the stack
	reached the max available length*/
	if(lifo_ptr->counter == lifo_ptr->length)
		return LIFO_FULL;
	return LIFO_NO_ERROR;
}

status_t LIFO__is_empty(LIFO_t* lifo_ptr){
	/*check that both lifo_ptr, and its base are valid pointers*/
	if(LIFO_is_valid(lifo_ptr) == LIFO_NULL)
		return LIFO_NULL;
	/*check if there is no lements in the LIFO*/
	if(lifo_ptr->counter == 0)
		return LIFO_EMPTY;
	return LIFO_NO_ERROR;
}

status_t LIFO_is_valid (LIFO_t* lifo_ptr){
	/*make sure both lifo_ptr and its base points to a non-NUL locations*/
	if(!lifo_ptr || !lifo_ptr->base)
		return LIFO_NULL;
	return LIFO_NO_ERROR;
}

void LIFO_print(LIFO_t* lifo_ptr){
	uint32_t i;
	printf("\n===========print LIFO contents from top to bottom===========\n");
	
	switch (LIFO__is_empty(lifo_ptr))
	{
	case LIFO_NULL:
		printf("ERROR!! LIFO is not valid\n");
		break;
	case LIFO_EMPTY:
		printf("the LIFO is Empty\n");
		break;
	
	default:
		i = lifo_ptr->counter ;
		while (i)
		{
			printf(format_specifier,lifo_ptr->base[--i]);
			printf("\n");
		}
		break;
	}
	printf("============================================================\n\n");
}