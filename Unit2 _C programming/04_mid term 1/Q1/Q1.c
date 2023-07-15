#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sumDigits(int);

int main(){
    int input, output;
    input = 123;
    output = sumDigits(input);
    printf("input = %d ----> output = %d\n",input, output);
    input = 4565;
    output = sumDigits(input);
    printf("input = %d ----> output = %d\n",input,output);

    system("pause");
    return 0;
}
int sumDigits(int num){
    char str[20];
    itoa(num,str, 10); /*convert int to string*/
    int sum = 0;
    int i = 0; /*iterator*/
    char c = str[i]; 
    while(c != 0){
        sum += c - 48; /*convert char to int*/
        c = str[++i];
    }
    return sum;
}