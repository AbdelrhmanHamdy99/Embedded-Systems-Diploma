#include<stdio.h>

int main(void){
    float a, b, c;
    
    printf("Enter three numbers: ");
    fflush(stdin);fflush(stdout);
    scanf("%f\r\n%f\r\n%f",&a,&b,&c);

    if(b>c){
        if(b > a)
            printf("Largest number = %.2f\r\n",b);
        else
            printf("Largest number = %.2f\r\n",a);
    }else{
        if(c > a)
            printf("Largest number = %.2f\r\n",c);
        else
            printf("Largest number = %.2f\r\n",a);
    }
    system("pause");
    return 0;
}
