#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double squareRootOfInteger(int);

int main(){
    int num;
    printf("enter a number: ");
    scanf("%d", &num);
    printf("square root of %d = %0.3lf\n",num,squareRootOfInteger(num));
    system("pause");
    return 0;
}

double squareRootOfInteger(int num){
    return sqrt(num);
}
