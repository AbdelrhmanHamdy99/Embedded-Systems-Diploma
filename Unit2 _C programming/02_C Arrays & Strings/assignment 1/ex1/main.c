#include "stdio.h"
int main(){
    float mat1[2][2], mat2[2][2];
    
    printf("Enter the elements of 1st matrix\r\n");
    int r; /*iterator for rows*/
    int c;  /*iterator for columns*/
    for (r = 0; r < 2; r++)
    {
        for (c = 0; c < 2; c++)
        {
            printf("Enter a%d%d: ",r+1 , c+1);
            scanf("%f",&mat1[r][c]);
        }
    }
    printf("Enter the elements of 2nd matrix\r\n");
    for (r = 0; r < 2; r++)
    {
        for (c = 0; c < 2; c++)
        {
            printf("Enter b%d%d: ",r+1 , c+1);
            scanf("%f",&mat2[r][c]);
        }
    }
        
    printf("Sum of matrix:\r\n");
    for (r = 0; r < 2; r++)
    {
        for (c = 0; c < 2; c++)
        {
            printf("%.1f\t",mat1[r][c] + mat2[r][c]);
        }
        printf("\r\n");
    }
    system("pause");
    return 0;
}