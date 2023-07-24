#include <stdio.h> 
#include <stdlib.h>

int main(){
    int arr1[100], arr2[100], temp[100];
    int size1, size2, i;
    
    printf("enter size of array1 (note that max size = 100): ");
    scanf("%d", &size1);
    if(size1 <= 0 || size1 > 100){
        printf("invalid array size!!\n");
        return 0;
    }

    printf("enter size of array2 (note that max size = 100): ");
    scanf("%d", &size2);
    if(size2 <= 0 || size2 > 100){
        printf("invalid array size!!\n");
        return 0;
    }
    
    /*start taking array elements*/
    printf("\nenter array1 elements:\n");
    for (i = 0; i < size1; i++)
    {
        printf("enter element%d: ",i + 1);
        scanf("%d", &arr1[i]);
    }

    printf("\nenter array2 elements:\n");
    for (i = 0; i < size2; i++)
    {
        printf("enter element%d: ",i + 1);
        scanf("%d", &arr2[i]);
    }
    int max;
    if(size1 > size2)
        max = size1;
    else
        max = size2;
    for(i = 0 ; i < max ; i++){
        temp[i] = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp[i];
    }

    /*print arrays after swapping*/
    printf("\n===================================\nafter swapping:");
    printf("\narry1 elements: ");
    for ( i = 0; i < size2; i++)
    {
        printf("%d  ",arr1[i]);
    }
    
    printf("\narry2 elements: ");
    for ( i = 0; i < size1; i++)
    {
        printf("%d  ",arr2[i]);
    }
    printf("\n");
    
    system("pause");
    return 0;
}