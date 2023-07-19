#include <stdio.h>
#include <stdlib.h>

struct SStudent
{
    char name[100];
    int roll;
    float marks;
} students[10] ;


int main(){
    
    printf("Enter informations of students:\n");
    int counter ;

    for(counter = 0; counter < 10; counter++){
        fflush(stdin);fflush(stdout);
        printf("\nFor roll number %d\n", counter + 1 );
        printf("Enter name: ");
        gets(students[counter].name);

        fflush(stdin);fflush(stdout);
        printf("Enter Marks: ");
        scanf("%f",&students[counter].marks);
        students[counter].roll = counter;
    }
    printf("\nDisplaying Information of students:\n\n");
    
    for (counter = 0; counter < 10; counter++)
    {
        printf("Information for roll number %d:\n", counter + 1);
        printf("Name: %s\nMarks: %.1f\n",students[counter].name,students[counter].marks);     
    }
    
    system("pause");
    return 0;
}
