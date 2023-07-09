#include <stdio.h>
#include <stdlib.h>
int prime(int);


int main(){
    printf("Enter two numbers(intervals): ");
    int n1,n2;
    scanf("%d\n%d",&n1,&n2);

    int start, end;
    if(n1 > n2){
        start = n2;
        end = n1;
    }else{
        start = n1;
        end = n2;
    }

     int i;
    printf("Prime numbers between %d and %d are:",start,end);
    for(;start <= end; start++){
        if(prime(start)){
            printf(" %d",start);
        }
    }
    printf("\n");

    system("pause");
    return 0;
}

int prime(int n){
    int mid = n / 2, i;
    
    for(i = 2 ; i <= mid; i++){
        if(n % i == 0)
            break;
    }
    return i > mid;
}