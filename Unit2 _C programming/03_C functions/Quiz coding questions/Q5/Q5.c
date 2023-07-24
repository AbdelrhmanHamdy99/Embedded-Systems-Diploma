#include <stdio.h>
#include <stdlib.h>

int clearABit(int num, int position){
    return num & ~(1<<position);
}

int main(){
    int input, bitPosition;
    printf("enter a number: ");
    scanf("%d", &input);

    printf("enter bit position to be cleared: ");
    scanf("%d", &bitPosition);

    int val = clearABit(input, bitPosition);
    printf("result = %d\n", val);
    system("pause");
    return 0;
}
