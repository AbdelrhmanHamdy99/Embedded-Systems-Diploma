#include <stdio.h>

void main(void){
	int m = 29;
	
	printf("Address of m: 0x%x\n", &m);
	printf("Value of m: %d\n", m);
	
	int* ab = &m;
	printf("\nNow ab is assigned with the address of m.\n");
	printf("Address of pointer ab : 0x%x\n", ab);
	printf("content of pointer ab : %d\n", *ab);
	
	m = 34;
	printf("\nthe value of m assigned to %d now.\n", m);
	printf("Address of pointer ab : 0x%x\n", ab);
	printf("content of pointer ab : %d\n", *ab);
	
	*ab = 7;
	printf("\nThe pointer variable ab is assigned with the value %d now.\n", *ab);
	printf("Address of m : 0x%x\n", &m);
	printf("Value of m : %d", m);
}