#ifndef SIS_H_
#define SIS_H_
#include "platform_Types.h"
#include <stdio.h>

#define MAX_STUDENTS 50
#define MAX_COURSES  7
#define MIN_COURSES  4

typedef enum {
	FAIL = 0,
	PASS = 1
}status_T;

typedef struct {
    char fname[50];
    char lname[50];
    int roll;
    float GPA;
    int cid[MAX_COURSES];
} student_t;

void add_student_file();
void add_student_file2();
void add_student_manually();
void find_rl();
void find_fn();
void find_c();
void tot_s();
void del_s();
void up_s();
void show_s();
void openning_Window();
void print_Generic_Info();
void print_Student_Info(uint32_t);
status_T read_student_gpa(FILE*);
sint32_t chk_roll_no(uint32_t);
uint32_t get_no_of_courses(uint32_t);
sint32_t get_course_index(uint32_t, uint32_t);
#endif