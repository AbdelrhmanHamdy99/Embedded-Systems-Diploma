#include<stdio.h>

int main(void){
    char c;
    
    printf("Enter an alphapet: ");
    fflush(stdin);fflush(stdout);
    c = getche();

    switch (c)
    {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
        printf("\r\n%c is a vowel\r\n",c);
        break;

    default:
        printf("\r\n%c is a consontant\r\n",c);
        break;
    }
    system("pause");
    return 0;
    
}
