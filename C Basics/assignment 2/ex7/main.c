#include<stdio.h>

int main(void){
    int n;
    int fact = 1;
    printf("Enter an integer: ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&n);
    if(n < 0){
        printf("Error!!! Factorial of negative number doesn't exist.\r\n");
        system("pause");
        return 0;
    }
    int i;
    for (i = 2; i <= n; i++)
    {
        fact *= i;
    }
    printf("Factorial = %d\r\n",fact);
    system("pause");
    return 0;
}
