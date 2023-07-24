#include <stdio.h>
#include <stdlib.h>

int solution(int* arr, int element, int size){
    int i;
    for(i = size - 1; i >= 0; i--){
        if(arr[i] == element)
            return i;
    }
    return -1;

}
int main(){
    int arr[] = {1,2,3,4,5,6,4};
    int num;
    
    printf("enter a number: ");
    scanf("%d", &num);

    printf("Array = {");
    int i;
    for ( i = 0; i < 7; i++)
    {
        if(i != 0)
            printf(",");
        printf("%d",arr[i]);
    }
    printf("} , this number is %d ==> result = %d\n",num, solution(arr,num, sizeof(arr) / sizeof(int)));
    
    system("pause");
    return 0;
}