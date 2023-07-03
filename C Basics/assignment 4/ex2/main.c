#include <stdio.h>

int main(){
    char str[50];

    printf("Enter a string: ");
    gets(str);
    
    int counter = 0; 
    int i = 0;
    while(str[i++] != 0){
        counter++;
    }
    printf("Length of string: %d\r\n", counter);

    system("pause");
    return 0;
}