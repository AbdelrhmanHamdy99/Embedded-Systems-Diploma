#include <stdio.h>

int main(){
    int arr[10];
    int n;

    printf("Enter no of elements : ");
    scanf("%d", &n);
    int i;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int element;
    printf("Engter the element to be searched : ");
    scanf("%d", &element);
    for ( i = 0; i < n; i++)
    {
        if(arr[i] == element){
            printf("Number found at location = %d\r\n", i + 1);
            break;
        }
    }
    if(i == n){
        printf("Number not Found\r\n");
    }
    system("pause");
    return 0;
}