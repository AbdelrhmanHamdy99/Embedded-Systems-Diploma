#include<stdio.h>

int main(void){
    char c;
    
    printf("Enter a character: ");
    fflush(stdin);fflush(stdout);
    c = getche();

    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
        printf("\r\n%c is an alphapet\r\n", c);
    }else{
        printf("\r\n%c is not an alphapet\r\n", c);
    }
    system("pause");
    return 0;
}
