#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sumDigits(int);

int main(){
    int input, output;
    printf("enter a number: ");
    scanf("%d", &input);
    output = sumDigits(input);
    printf("input = %d ----> output = %d\n",input, output);

    system("pause");
    return 0;
}
int sumDigits(int num){
    static int sum = 0;
    /*stopping condition*/
    if(num == 0 )
        return 0;
    sum += num % 10;
    sumDigits(num / 10);
    return sum;
}