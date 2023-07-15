#include <stdio.h>
#include <stdlib.h>

void reverseArrayElements(int*,int);

int main(){
    int a[5] = {1,2,3,4,5};

    printf("original array:\n");
    int i = 0;
    while(i < 5)
        printf("%d   ",a[i++]);
    printf("\n===============================\n");
    
    reverseArrayElements(a,5);
    printf("revesed array:\n");
    for(i = 0 ; i < 5; i++)
        printf("%d   ",a[i]);
    printf("\n");
    
    system("pause");
    return 0;
}

void reverseArrayElements(int* arr,int size){
    int i = 0;
    /*reverse elements*/
    while(i < --size){
        int temp = arr[i];
        arr[i++] = arr[size];
        arr[size] = temp;
    }
}