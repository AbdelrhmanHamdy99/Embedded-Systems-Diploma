#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char*,int);

int main(){
    char input1[] = "mohamed gamal";
    printf("test case 1:\noriginal string: %s\n",input1);
    
    reverseString(input1,strlen(input1));
    printf("revesed string: %s\n=================\n",input1);

    char input2[] = "Abdelrhman Hamdy Zakaria Mohamed";
    printf("test case 2:\noriginal string: %s\n",input2);
    
    reverseString(input2,strlen(input2));
    printf("revesed string: %s\n================\n",input2);
    
    system("pause");
    return 0;
}

void reverseString(char arr[], int length){
    int i = 0;/*iterator on original array*/
    
    char str1[length + 1];
    int j = 0; /*str1 iterator*/
    
    char c  = arr[0]; /*used to traverse original string char by char*/
    while(c != 0){
        if(c == ' '){
            /*skip spaces at the beginning*/
            if(i == 0){
                c = arr[++i];
                continue;
            }
            str1[j++] = 0;
            char str2[length + 1];
            int k = 0; /*str2 iterator*/
            char c = arr[++i];
            while (c !=0 && c != ' ')
            {
                str2[k++] = c;
                c = arr[++i]; 
            }
            str2[k++] = ' ';
            str2[k] = 0;
            strcpy(str1, strcat(str2,str1));
            j = i;
        }
        else{
            str1[j++] = c;
            i++;
        }
        c = arr[i];
    }
    strcpy(arr, str1);
}