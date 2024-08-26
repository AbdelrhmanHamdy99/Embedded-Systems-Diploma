/*
 * test_FIFO.c
 *
 *  Created on: Aug 25, 2024
 *      Author: AbdoHamdy
 */

#include "FIFO.h"
#include "Platform_types.h"
#include <stdio.h>
#include <stdlib.h>

/*macro to test all APIs and functionalities*/
#define test_FIFO_fun(fun_name,...)   switch(fun_name(__VA_ARGS__)){\
										case FIFO_FULL:\
											printf("*****ERROR in %s!! the FIFO is full!!*****\n",#fun_name);\
											break;\
										case FIFO_EMPTY:\
											printf("*****ERROR in %s!! the FIFO is empty!!*****\n",#fun_name);\
											break;\
										case FIFO_NULL:\
											printf("*****ERROR in %s!! there is no FIFO at all!!*****\n",#fun_name);\
											break;\
										case FIFO_LENGTH_ERROR:\
											printf("*****ERROR in %s!! FIFO length must be a valid number!!*****\n",#fun_name);\
											break;\
										case FIFO_NO_ERROR:\
											printf("*****%s is done successfully*****\n",#fun_name);\
											break;\
										default:\
											printf("*****unknown ERROR in %s!!*****\n",#fun_name);\
									  }
#define MAX_LEN      5

int main(void){
	FIFO_t test_FIFO;
	element_type stack[MAX_LEN];
	uint32_t i;/*iterator*/
	element_type element; /*to carry dequeueed elements*/

	/*test using NULL pointers*/
	test_FIFO_fun(FIFO_create,NULL,stack,MAX_LEN);
	test_FIFO_fun(FIFO_create,&test_FIFO,NULL,MAX_LEN);

	/*test passing invalid length*/
	test_FIFO_fun(FIFO_create,&test_FIFO,stack,0);

	/*successfully create a FIFO*/
	test_FIFO_fun(FIFO_create,&test_FIFO,stack,MAX_LEN);

	/*try to print contents of an empty FIFO*/
	FIFO_print(&test_FIFO);

	/*try to dequeue from an empty FIFO*/
	test_FIFO_fun(FIFO_dequeue,&test_FIFO,&element);

	/*test enqueu*/
	for (i=0; i < MAX_LEN + 3;)
	{
		test_FIFO_fun(FIFO_enqueue,&test_FIFO,++i);
	}
	
	/*print current contents*/
	FIFO_print(&test_FIFO);
    
	/*try to dequeue from a FIFO*/
	test_FIFO_fun(FIFO_dequeue,&test_FIFO,&element);
	printf("dequeueed element = ");
	printf(format_specifier,element);
	printf("\n");

	test_FIFO_fun(FIFO_dequeue,&test_FIFO,&element);
	printf("dequeueed element = ");
	printf(format_specifier,element);
	printf("\n");
	
	/*print current contents*/
	FIFO_print(&test_FIFO);

	/*try to enqueue more two elements to check circularity*/
	test_FIFO_fun(FIFO_enqueue,&test_FIFO,9);
	test_FIFO_fun(FIFO_enqueue,&test_FIFO,10);
	
	/*print current contents*/
	FIFO_print(&test_FIFO);

	/*dequeue remaining elements to check circularity working well in case of dequeue*/
	for ( i = 0; i < MAX_LEN; i++)
	{
		test_FIFO_fun(FIFO_dequeue,&test_FIFO,&element);
		printf("dequeueed element = ");
		printf(format_specifier,element);
		printf("\n");
	}
	
	/*print FIFO contents after dequeuing all elements*/
	FIFO_print(&test_FIFO);

    system("pause");
	return 0;
}
