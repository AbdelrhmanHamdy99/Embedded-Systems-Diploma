#include<stdio.h>

int main(void){
    int in;
    printf("Enter a integer: ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&in);
    printf("entered: %d\r\n",in);
    
    system("pause");
    return 0;
    
}
