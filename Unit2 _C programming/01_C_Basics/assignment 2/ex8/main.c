#include<stdio.h>

int main(void){
    float in1, in2;
    char choice;
    float out;
    printf("Enter operator either + or - or * or /: ");
    fflush(stdin);fflush(stdout);
    choice = getche();
    if(choice != '+' && choice != '-' && choice != '*' && choice != '/'){
        printf("\r\nIncorrect operator!!\r\n");
        system("pause");
        return 0;
    }
    printf("\r\nEnter two operands: ");
    fflush(stdin);fflush(stdout);
    scanf("%f\r\n%f",&in1,&in2);
    switch (choice)
    {
    case '+':
        out = in1 + in2;
        break;
    
    case '-':
        out = in1 - in2;
        break;
    
    case '*':
        out = in1 * in2;
        break;
    
    case '/':
        out = in1 / in2;
        break;
    }
    printf("%.1f %c %.1f = %.1f\r\n",in1,choice, in2 , out);
    system("pause");
    return 0;
}
