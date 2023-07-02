#include<stdio.h>

int main(void){
    char in;
    printf("Enter a character:");
    fflush(stdin);fflush(stdout);
    scanf("%c",&in);
    printf("ASCII value of G = %d\r\n",in);
    
    system("pause");
    return 0;
    
}
