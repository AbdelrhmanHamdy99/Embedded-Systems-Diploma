#include<stdio.h>

int main(void){
    float a, b;
    
    printf("Enter value of a: ");
    fflush(stdin);fflush(stdout);
    scanf("%f",&a);

    printf("Enter value of b: ");
    fflush(stdin);fflush(stdout);
    scanf("%f",&b);

    float temp = a;
    a = b; 
    b = temp;

    printf("After swapping, value of a = %.2f\r\nAfter swapping, value of b = %.1f\r\n",a,b);
    system("pause");
    return 0;
    
}
