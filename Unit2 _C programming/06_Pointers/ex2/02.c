#include <stdio.h>

void main(void){
	char c = 'A';
	char* pc = &c;
	
	int i;
	printf("The Alphabets are:\n");
	for(i = 0 ; i < 26; i++){
		printf("%c  ",(*pc)++);
	}
}