#include <stdio.h>
#include <conio.h>

int main(){
    
    char str[50];
    printf("ُEnter a string: ");
    gets(str);
    printf("Enter a character to find frequency: ");
    char c = getche();

    int counter = 0;
    int i = 0;
    
    while(str[i] != 0){
        if(str[i] == c){
            counter ++;
        }
        i++;
    }
    printf("\r\nFrequency of %c = %d\r\n",c,counter);
    system("pause");
    return 0;
}