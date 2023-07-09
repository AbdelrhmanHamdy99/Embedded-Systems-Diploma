#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char*,int,int);
int main(){
    char str[50];
    printf("Enter a sentence: ");
    gets(str);
    int len = strlen(str);
    reverse(str,0, len - 1);
    printf("\n");
    system("pause");
    return 0;
}

void reverse(char* str, int index, int end){
    if(index == end){
        printf("%c", str[index]);
        return;
    }
    reverse(str,index + 1, end);
    printf("%c", str[index]);
}