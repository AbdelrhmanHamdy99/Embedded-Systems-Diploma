#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int power(int,int);

int main(){
    int num, pow;
    printf("Enter base number: ");
    scanf("%d", &num);

    printf("Enter power number(positive integer): ");
    scanf("%d", &pow);
    if(pow < 0){
        printf("Wrong Power\n");
        return 0;
    }
    if(pow == 0){
        printf("%d^%d = %d",num,pow,1);
        return 0;
    }
    int result = power(num, pow);
    printf("%d^%d = %d\n",num,pow,result);

    system("pause");
    return 0;
}
int power(int num, int pow){
    if(pow == 1)
        return num;
    return num * power(num, pow - 1);
}
