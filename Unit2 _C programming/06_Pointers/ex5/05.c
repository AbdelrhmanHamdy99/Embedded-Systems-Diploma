#include <stdio.h>

struct employee{
	char* name;
	int ID;
};

void main(void){
	struct employee* pEmployees[10];/*create array of pointers to structs*/
	struct employee alex;
	
	pEmployees[0] = &alex; /*point to a structure*/
	
	pEmployees[0]->name = "Alex";
	pEmployees[0]->ID = 1002;
	
	printf("First Employee data:\n");
	printf("Employee Name: %s\n",pEmployees[0]->name);
	printf("Employee Name: %d\n",pEmployees[0]->ID);
}