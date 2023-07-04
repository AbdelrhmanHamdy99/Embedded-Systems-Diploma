#include<stdio.h>

int main(void){
    int a;
    
    printf("Enter an integer you want to check: ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&a);

    if(a %2 == 0){
        printf("%d is even.\r\n",a);
    }else{
        printf("%d is odd.\r\n",a);
    }
    system("pause");
    return 0;
    
}
