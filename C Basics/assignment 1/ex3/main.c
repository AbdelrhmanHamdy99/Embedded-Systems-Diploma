#include<stdio.h>

int main(void){
    int in1,in2;
    printf("Enter two integers: ");
    fflush(stdin);fflush(stdout);
    scanf("%d\r\n%d",&in1, &in2);
    printf("sum: %d\r\n",in1 + in2);
    
    system("pause");
    return 0;
    
}
