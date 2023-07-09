#include <stdio.h>
void prime(int,int);


int main(){
    printf("Enter two numbers(intervals): ");
    int n1,n2;
    scanf("%d\n%d",&n1,&n2);
    prime(n1,n2);

    system("pause");
    return 0;
}

void prime(int n1, int n2){
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
        int mid = start / 2;
        for(i = 2 ; i <= mid; i++){
            if(start % i == 0)
                break;
        }
        if(i > mid){
            printf(" %d", start);
        }
    }
    printf("\n");
}