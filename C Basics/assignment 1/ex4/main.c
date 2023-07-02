#include<stdio.h>

int main(void){
    float in1,in2;
    printf("Enter two numbers: ");
    fflush(stdin);fflush(stdout);
    scanf("%f\r\n%f",&in1, &in2);
    printf("sum: %f\r\n",in1 * in2);
    
    system("pause");
    return 0;
    
}
