#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(int);

int main(){
    int in;
    printf("enter a number: ");
    scanf("%d",&in);
    
    reverse(in);
    
    system("pause");
    return 0;
}

void reverse(int num){
    char str[15];
    itoa(num,str, 10); /*convert int to string*/
    int i = 0;
    int j = strlen(str) - 1;
    while(i < j ){
        char c = str[i];
        str[i++] = str[j];
        str[j--] = c;
    }
    
    printf("num %d reversed digits form = %s\n",num , str);

}