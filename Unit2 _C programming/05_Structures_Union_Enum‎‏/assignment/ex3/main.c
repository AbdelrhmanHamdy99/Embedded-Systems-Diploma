#include "stdio.h"
#include "stdlib.h"

struct SComplex{
    float real;
    float imj;
};

struct SComplex read(void);
struct SComplex add(struct SComplex , struct SComplex);
int main(){
    struct SComplex num1;
    struct SComplex num2;
    
    printf("For 1st Complex number\n");
    num1 = read();
    
    printf("\nFor 2nd Complex number\n");
    num2 = read();
    
    struct SComplex result = add(num1, num2 );

    printf("\nSum = %.1f+%.1fi\n",result.real, result.imj);
    system("pause");
    return 0;
}

struct SComplex read(void){
    struct SComplex num;
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f",&num.real, &num.imj);
    return num;
}

struct SComplex add(struct SComplex num, struct SComplex num2){
    struct SComplex res;
    res.real = num.real + num2.real;
    res.imj = num.imj + num2.imj;
    return res;
}
