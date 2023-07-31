#include <stdio.h>

void main(void){
	int arr[15];
	int *pt = arr;
	int n; /*number of elements*/
	
	printf("Input the number of elements to store in the array (max 15) :");
	scanf("%d", &n);
	
	if(n > 15 || n < 1){
		printf("Invalid size\n");
		return;
	}
	
	int i;
	printf("Input %d number of elements in the array:\n", n);
	
	for(i = 0; i < n ; i++){
		printf("element - %d: ", i+1);
		scanf("%d", pt++);
	}
	
	printf("\nThe elements of array in reverse order are :\n");
	for(; n-- > 0;){
		printf("element - %d: %d\n", n+1, *(--pt));
	}		
}