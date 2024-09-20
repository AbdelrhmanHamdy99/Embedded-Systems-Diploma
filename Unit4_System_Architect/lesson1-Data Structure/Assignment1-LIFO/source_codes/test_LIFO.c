/*
 * test_LIFO.c
 *
 *  Created on: Aug 25, 2024
 *      Author: AbdoHamdy
 */

#include "LIFO.h"
#include "Platform_types.h"
#include <stdio.h>
#include <stdlib.h>

/*macro to test all APIs and functionalities*/
#define test_lifo_fun(fun_name,...)   switch(fun_name(__VA_ARGS__)){\
										case LIFO_FULL:\
											printf("*****ERROR in %s!! the LIFO is full!!*****\n",#fun_name);\
											break;\
										case LIFO_EMPTY:\
											printf("*****ERROR in %s!! the LIFO is empty!!*****\n",#fun_name);\
											break;\
										case LIFO_NULL:\
											printf("*****ERROR in %s!! there is no LIFO at all!!*****\n",#fun_name);\
											break;\
										case LIFO_LENGTH_ERROR:\
											printf("*****ERROR in %s!! LIFO length must be a valid number!!*****\n",#fun_name);\
											break;\
										case LIFO_NO_ERROR:\
											printf("*****%s is done successfully*****\n",#fun_name);\
											break;\
										default:\
											printf("*****unknown ERROR in %s!!*****\n",#fun_name);\
									  }
#define MAX_LEN      5
int main(void){
	LIFO_t test_lifo;
	element_type stack[MAX_LEN];
	uint32_t i;/*iterator*/
	element_type element; /*to carry poped elements*/

	/*test using NULL pointers*/
	test_lifo_fun(LIFO_create,NULL,stack,MAX_LEN);
	test_lifo_fun(LIFO_create,&test_lifo,NULL,MAX_LEN);

	/*test passing invalid length*/
	test_lifo_fun(LIFO_create,&test_lifo,stack,0);

	/*successfully create a LIFO*/
	test_lifo_fun(LIFO_create,&test_lifo,stack,MAX_LEN);

	/*try to print contents of an empty LIFO*/
	LIFO_print(&test_lifo);

	/*try to pop from an empty LIFO*/
	test_lifo_fun(LIFO_pop,&test_lifo,&element);

	/*try to get the top element from an empty list*/
	test_lifo_fun(LIFO_top,&test_lifo,&element);

	/*test push*/
	for (i=0; i < MAX_LEN + 3;)
	{
		test_lifo_fun(LIFO_push,&test_lifo,++i);
	}
	
	/*print current contents*/
	LIFO_print(&test_lifo);
    
	/*try to pop from a LIFO*/
	test_lifo_fun(LIFO_pop,&test_lifo,&element);
	printf("poped element = ");
	printf(format_specifier,element);
	printf("\n");

	test_lifo_fun(LIFO_pop,&test_lifo,&element);
	printf("poped element = ");
	printf(format_specifier,element);
	printf("\n");
	
	/*print current contents*/
	LIFO_print(&test_lifo);

	/*try to get the top element from an empty list*/
	test_lifo_fun(LIFO_top,&test_lifo,&element);
	printf("top element = ");
	printf(format_specifier,element);
	printf("\n");
	test_lifo_fun(LIFO_top,&test_lifo,&element);
	printf("top element = ");
	printf(format_specifier,element);
	printf("\n");
	
	/*print current contents*/
	LIFO_print(&test_lifo);

    system("pause");
	return 0;
}
