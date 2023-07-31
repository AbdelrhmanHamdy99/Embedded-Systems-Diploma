#include <stdio.h>
#include <string.h>

void main(void){
	char c[50];
	printf("Input a string: ");
	scanf("%s", c);
	
	int len = strlen(c);
	
	char *pc = c + len - 1;
	
	int i = 0;
	for(;i < len; i++){
		printf("%c", *(pc- i));
	}
}