#include<stdio.h>

int main(){
    int arr[10];
    int n;
    printf("Enter no of elements: ");
    scanf("%d", &n);

    int i; /*iterator*/
    /*get elements from user*/
    for(i = 0; i < n ; i++){
        scanf("%d", &arr[i]);
    }

    int element, position;
    do{
        printf("\r\nEnter the element to be inserted: ");
        scanf("%d",&element);
        printf("Enter the location: ");
        scanf("%d",&position);
        /*wrong position*/
        if(position > 10 && position < 1){
            printf("wrong position\r\n");
            break;
        }
            
        /*i = n "right now"*/
        /*move elements one step backward to free up the required position*/
        for(; i >= position; i--){
            arr[i] = arr[i- 1];
        }

        /*now insert the element at position - 1*/
        arr[position - 1] = element;
        n++;

        /*print current array after insertion*/
        for(i = 0 ; i < n ; i++){
            printf("%d ",arr[i]);
        }
        printf("\r\ndo you want to insert again? (y / n): ");
    }while(getche() == 'y' && n < 11);
    printf("\r\n");
    system("pause");
    return 0;
}