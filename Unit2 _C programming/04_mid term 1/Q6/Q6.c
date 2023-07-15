#include<stdio.h>
#include<stdlib.h>

int unique(int*,int);

int main(){
    int a[7]={4,2,5,2,5,7,4};
    int out1 = unique(a,7);

    int b[3]={4,2,4};
    int out2 =  unique(b,3);

    /*printing*/
    printf("test Case1:\n");
    int i;
    for(i = 0; i < 7 ; i++)
        printf("%d   ",a[i]);
    printf("\r\n");
    printf("unique: %d\n", out1);
    printf("==============================================\ntest case2:\n");
    for(i = 0; i < 3 ; i++)
        printf("%d   ",b[i]);
    printf("\r\n");
    printf("unique: %d\n", out2);

    system("pause");
    return 0;
}
/*assume arr[i] >= 0 and <= 9*/
int unique(int* arr, int size){
    int freqArr[10]= {0};
    int i = 0;
    while(i < size){
        freqArr[arr[i++]]++;
    }
    
    for(i = 0; i < 10; i++){
        if(freqArr[i] == 1)
        return i;
    }
}