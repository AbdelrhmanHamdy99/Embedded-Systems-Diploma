#include <stdio.h>
#include <stdlib.h>

int count(int);

int main(){
    printf("enter a number: ");
    int num;
    scanf("%d",&num);

    int n= count(num);
    printf("max number of ones between two zeros = %d\n", n);
    system("pause");
    return 0;
}

int count(int num){
    int max = 0;
    int counter = 0;

    int flag = 0;
    while (num > 0)
    {
        if(num % 2 == 0){
            max = counter > max ? counter : max;
            counter = 0;
            flag = 1;
        }
        else{
            if(flag)
                counter++;
        }
        num /= 2;
    }
    return max > counter ? max : counter;
}