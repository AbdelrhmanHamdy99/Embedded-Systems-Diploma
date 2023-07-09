#include <stdio.h>
#include <stdlib.h>

int factorial(int);

int main(){
    printf("Enter a positive integer: ");
    int n;
    scanf("%d", &n);
    if(n < 0){
        printf("wrong input\n");
        return 0;
    }
    int res = factorial(n);
    printf("Factorial of %d = %d\n", n , res);

    system("pause");
    return 0;
}

int factorial(int num){
    if(num == 0){
        return 1;
    }
    if(num < 3){
        return num;
    }
    return num * factorial(num - 1);
}