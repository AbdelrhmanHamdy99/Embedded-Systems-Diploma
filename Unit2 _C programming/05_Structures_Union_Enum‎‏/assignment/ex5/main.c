#include "stdio.h"
#include "stdlib.h"

#define PI 3.14
#define area(r) PI * r * r

int main(){
    float radius ;
    printf("Enter the radius: ");
    scanf("%f", &radius);
    float res = area(radius);
    printf("Area=%.2f\n",res);

    system("pause");
    return 0;
}