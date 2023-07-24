#include <stdio.h>
#include <stdlib.h>

void reverseArr(int arr[], int size){
    int reverseArr[size];
    int i, j;
    for(i = 0, j = size - 1 ; i < size; i++, j--){
        reverseArr[j] = arr[i];
    }
    for(i = 0; i < size; i++){
        arr[i] = reverseArr[i];
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6};
    printf("Input: ");
    int i ;
    for ( i = 0; i < 6; i++)
    {
        printf("%d, ", arr[i]);
    }
    
    reverseArr(arr,sizeof(arr) / sizeof(int));
    
    printf("\nOutput: ");
    for (i = 0; i < 6; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    

    system("pause");
}