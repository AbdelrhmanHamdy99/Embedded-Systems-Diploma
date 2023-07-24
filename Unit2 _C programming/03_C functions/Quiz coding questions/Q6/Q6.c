#include <stdio.h>
#include <stdlib.h>
int solution1(int);
int solution2(int);

int main(){
    int num;
    printf("Enter a number to get it's 4th least bit: ");
    scanf("%d", &num);

    printf("\nafter clearing:\n");
    printf("result from func 1 = %d\n", solution1(num));
    printf("result from func 2 = %d\n", solution2(num));
    system("pause");
    return 0;
}

int solution1(int num){
    int counter = 0;
    while(num){
        if(++counter == 4){
            return num % 2;
        }
        num /= 2;
    }
    return 0;
}

int solution2(int num){
    num &= 1<<3;
    return num >> 3;
}
