#include<stdio.h>

int main(void){
    float a;
    
    printf("Enter a number: ");
    fflush(stdin);fflush(stdout);
    scanf("%f",&a);

    if(a > 0){
        printf("%.2f is positive\r\n", a);
    }else if(a == 0){
        printf("you entered zero.\r\n");
    }else{
        printf("%.2f is negative\r\n", a);
    }
    system("pause");
    return 0;
}
