#include <stdio.h>

int main(){
    int mat[10][10], transpose[10][10];

    int row,column;
    printf("Enter rows and columns of matrix: ");
    scanf("%d %d", &row, &column);
    printf("\r\nEnter elements of matrix:\r\n");

    int r,c; /*iterators*/
    /*store original matrix*/
    for(r = 0; r < row; r++){
        for(c = 0 ; c < column; c++){
            printf("Enter element a%d%d: ",r+1 , c + 1);
            scanf("%d",&mat[r][c]);
        }
    }
    /*get transpose of matrix*/
    for (r = 0; r < row; r++)
    {
        for(c = 0 ; c < column ; c++){
            transpose[c][r] = mat[r][c];
        }
    }
    
    /*print original matrix*/
    printf("Entered Matrix:\r\n");
    for (r = 0; r < row; r++)
    {
        for (c = 0; c < column; c++)
        {
            printf("%d\t",mat[r][c]);
        }
        printf("\r\n");
    }
    /*print transpose*/
    printf("Transpose of Matrix:\r\n");
    for(c  = 0 ; c < column; c++){
        for( r= 0 ; r < row; r++){
            printf("%d\t",transpose[c][r]);
        }
        printf("\r\n");
    }

    system("pause");
    return 0;
}