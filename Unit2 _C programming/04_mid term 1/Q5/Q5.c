#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int countOnes(int);

int main(){
    printf("enter a number: ");
    int num;
    scanf("%d",&num);

    int res = countOnes(num);
    printf("input: %d ---> output: %d\n", num, res);
    system("pause");
    
}

int countOnes(int num){
    int counter = 0;
    while(num > 0){
        if(num % 2 == 1)
            counter++;
        num /= 2;
    }
    return counter;
}