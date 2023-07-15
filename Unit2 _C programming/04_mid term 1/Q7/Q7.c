#include <stdio.h>
#include <stdlib.h>

int arithmeticSum(int,int);

int main(){
    int s = 1, e = 100;
    int res = arithmeticSum(s,e);
    printf("sum numbers from %d to %d = %d\n", s, e, res);

    system("pause");
    return 0;
}

int arithmeticSum(int start, int end){
    int sum = start + end;
    float count = (end - start + 1) / 2.0f;
    return sum * count;
}