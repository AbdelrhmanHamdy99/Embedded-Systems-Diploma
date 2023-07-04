#include <stdio.h>
int main(){
    /*define an array with the maximum predicted size as arrays must have fixed size*/
    float arr[10];  /*assume max numbe of elements = 10*/
    
    int n; 
    float sum = 0;
    int i; /*iterator*/

    printf("Enter the number of data: ");
    scanf("%d", &n);

    /*store data in an array*/
    for(i = 0 ; i < n ; i++){
        printf("%d. Enter number: ",i+1);
        scanf("%f",&arr[i]);
    }
    /*start calculations*/
    for(i = 0; i < n ; i++){
        sum += arr[i];
    }
    printf("Average = %.2f\r\n", sum / n );
    system("pause");
    return 0;
}