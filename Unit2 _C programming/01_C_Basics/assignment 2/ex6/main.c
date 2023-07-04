#include<stdio.h>

int main(void){
    int n;
    int sum = 0;
    printf("Enter an integer: ");
    fflush(stdin);fflush(stdout);
    scanf("%d",&n);
    int i;
    for (i = 1; i <= n; i++)
    {
        sum+= i;
    }
    printf("Sum = %d\r\n",sum);
    system("pause");
    return 0;
}
