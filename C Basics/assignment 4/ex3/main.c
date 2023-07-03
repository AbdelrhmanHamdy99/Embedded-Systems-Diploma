#include <stdio.h>
#include <string.h>

int main(){
    char str[50], reversed_str[50];

    printf("Enter the string : ");
    gets(str);

    int len = strlen(str);
    int i = 0;
    int j = len - 1;
    
    for(; i < len; i++, j--){
        reversed_str[i] = str[j];
    }

    printf("Reverse string is : %s\r\n", reversed_str);
    system("pause");
    return 0;
}