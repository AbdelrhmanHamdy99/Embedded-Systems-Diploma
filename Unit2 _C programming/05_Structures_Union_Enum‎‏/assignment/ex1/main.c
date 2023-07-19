#include <stdio.h>
#include <stdlib.h>

struct SStudent
{
    char name[100];
    int roll;
    float marks;
};

struct SStudent readStudent(void);
void printInfo(struct SStudent);

int main(){
    printf("Enter informations of students:\n\n");
    struct SStudent student1 = readStudent();

    printf("\nDisplaying Information\n");
    printInfo(student1);
    system("pause");
    return 0;
}

struct SStudent readStudent(void){
    struct SStudent student;
    
    printf("Enter name: ");
    gets(student.name);
    printf("Enter roll number: ");
    scanf("%d", &student.roll);
    printf("Enter Marks: ");
    scanf("%f",&student.marks);
    return student;
}

void printInfo(struct SStudent student){
    printf("Name: %s\nRoll: %d\nMarks: %.1f\n",student.name,student.roll,student.marks);
}