#include "SIS.h"
#include "platform_Types.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h> /*getch()*/
#include <string.h> /*strcmpi()*/

#define DPRINTF(...)    fflush(stdin); \
                        fflush(stdout); \
                        printf(__VA_ARGS__);

#define ERROR(...)      printf("[ERROR] ");\
                        printf(__VA_ARGS__);

#define WARNNING(...)   printf("[WARN]  ");\
                        printf(__VA_ARGS__);

#define INFO(...)       printf("[INFO]  ");\
                        printf(__VA_ARGS__);
                
student_t st[MAX_STUDENTS]; /*students DB*/
uint32_t  nStudents = 0; /*number of students in the DB*/

/*add students from text file*/
void add_student_file(){
    sint8_t  i;  /*helpful iterator*/
    sint32_t id; /*helpful var*/
    FILE *file;  /*file pointer*/
    char source_file[250];
    DPRINTF("Enter the source file path: ");
    scanf("%s",source_file);
    
    /*open the file in read mode and check it's validity*/
    if(!(file = fopen(source_file,"r"))){
        ERROR("file opening failed\n");
        return;
    }
    /*student data format :
     roll fname lname GPA courses_list */

    fscanf(file,"%lu",&id); /*scan the roll number*/

    /*loop to read each student's data*/
    while (!feof(file))
    {
        /*check for uniqueness of roll number*/
        if(chk_roll_no(id) < 0){
            st[nStudents].roll = id;
            /*get student fname, lname*/
            fscanf(file,"%s %s",st[nStudents].fname,st[nStudents].lname);
            
            /*read GPA and check it*/
            /*1. A or A+ instead of 4.0 */
            if(fscanf(file,"%f",&st[nStudents].GPA) != 1){
                // Skip this line using fscanf to read and discard the rest of the line
                fscanf(file, "%*[^\n]%*c");
                ERROR("Roll number %d Non numeric GPA\n",st[nStudents].roll);
                fscanf(file,"%ld",&id); /*get the id of the next student*/
                continue;
            }

            
            /*read courses IDs*/
            for (i = 0; (i < MAX_COURSES)  && ((id = fscanf(file,"%d",&st[nStudents].cid[i])) == 1);i++);

            if((st[nStudents].GPA < 0.0f ||st[nStudents].GPA > 4.0f) && (i>0 || id == -1)){
                ERROR("Roll Number %d GPA must be [0.0, 4.0]\n",st[nStudents].roll);
                id = st[nStudents].cid[i-1];
                continue;
            }else if(id == -1){/*EOF*/
                st[nStudents].cid[i] = -1; /*null terminator*/
            }else if(i <= MIN_COURSES){
                if(!i){
                    id = st[nStudents].GPA;
                }else{
                    id = st[nStudents].cid[i -1];
                }
                ERROR("Roll Number %d must enroll in at least %u courses\n",st[nStudents].roll,MIN_COURSES);
                continue;
            }else if(id == 0){ /*fname*/
                id = st[nStudents].cid[i-1];
                st[nStudents].cid[i-1] = -1; /*null terminator*/
            }else if(i == MAX_COURSES){ /*all courses fields had been seized*/
                /*1. last entry was the roll number of the second student*/
                if(fscanf(file,"%ld",&id) != 1){
                    id = st[nStudents].cid[i-1];
                    st[nStudents].cid[i-1] = -1; /*null terminator*/
                }else if(fscanf(file,"%ld",&id) == 1){
                    /*2. number of courses greater than the MAX_COURSES allowed*/
                    while (fscanf(file,"%ld",&id) == 1); /*skip the remaining courses*/
                    ERROR("Roll number %d Number of courses > %d\n",st[nStudents].roll,MAX_COURSES); /*fire an error*/
                    continue;
                }
                /*3. number of courses are exactly = MAX_COURSES*/
            }else { 
                ERROR("Unknown\n");
            }
            INFO("Roll Number %d saved successfully\n",st[nStudents++].roll);
        } else{
            ERROR("Roll number %lu is already taken\n",id);
            /* Skip this line using fscanf to read and discard the rest of the line*/
            fscanf(file, "%*[^\n]%*c");
            /*get next student roll number*/
            fscanf(file,"%lu",&id);
        }
            
    }
    fclose(file);

    tot_s();
}

void add_student_file2(){
    FILE *file;  /*file pointer*/
    char line[256]; /*to store line data*/
    char element[50]; /*to store element*/
    uint16_t l = 0; /*lines counter*/
    uint16_t i,j,k; /*iterators*/
    uint8_t err_flag;
    char source_file[250];
    DPRINTF("Enter the source file path: ");
    scanf("%s",source_file);
    /*open the file in read mode*/
    file = fopen(source_file,"r");

    /*file not valid*/
    if(!file){
        ERROR("file opening failed\n");
        return;
    }
    /*read file line by line*/
    while (fscanf(file, " %[^\n]", line) != EOF)
    {
        err_flag = 0;
        l++;
        i = 0;
        st[nStudents].roll = 0; /*init roll number to zero*/
        /*parsing stage*/
        /*skip white spaces*/
        while (line[i] == ' ')
        {
            i++;
        }
        
        /*1. read roll num*/
        while(line[i] && line[i] != ' '){
            if(line[i] >= '0' && line[i] <= '9'){
                st[nStudents].roll *= 10;
                st[nStudents].roll += (line[i++] - '0');
            }else{
                ERROR("Line %hu Roll Number Must be a unique positive integer number\n", l);
                err_flag = 1;
                break;
            }
        }
        /*check for error*/
        if(err_flag)
            continue;
        /*check for incomplete data*/
        if(!line[i]){
            ERROR("Line %hu Roll Number %d Incomplete entry\n", l,st[nStudents].roll);
            continue;
        }
        /*check for roll number uniqueness*/
        j = 0;
        while(j < nStudents){
            if(st[j++].roll == st[nStudents].roll){
                ERROR("Line %hu Roll Number %d is already taken\n",l,st[nStudents].roll);
                err_flag=1;
                break;
            }
        }
         /*check for error*/
        if(err_flag)
            continue;

        /*skip white spaces*/
        while (line[i] == ' ')
        {
            i++;
        }

        /*2. read fname*/
        j = 0;
        while(line[i] && line[i] != ' '){
            st[nStudents].fname[j++] = line[i++];
        }
        st[nStudents].fname[j++] = 0;
        /*check for incomplete data*/
        if(!line[i]){
            ERROR("Line %hu Roll Number %d Incomplete entry\n", l, st[nStudents].roll);
            continue;
        }

        /*skip white spaces*/
        while (line[i] == ' ')
        {
            i++;
        }

        /*3. read lname*/
        j = 0;
        while(line[i] && line[i] != ' '){
            st[nStudents].lname[j++] = line[i++];
        }
        st[nStudents].lname[j++] = 0;
        /*check for incomplete data*/
        if(!line[i]){
            ERROR("Line %hu Roll Number %d Incomplete entry\n", l, st[nStudents].roll);
            continue;
        }

        /*skip white spaces*/
        while (line[i] == ' ')
        {
            i++;
        }

        /*4. read GPA*/
        j = 0, k = 0;
        while(line[i] && line[i] != ' '){
            if(line[i] >= '0' && line[i] <= '9'){
                element[j++] = line[i++];
            }else if (line[i] == '.')
            {
                if(k++){
                    ERROR("Line %hu Roll Number %d GPA Must be a positive float number\n", l, st[nStudents].roll);
                    err_flag = 1;
                    break;
                }
                element[j++] = line[i++];
            }else{
                ERROR("Line %hu Roll Number %d GPA Must be a positive float number\n", l, st[nStudents].roll);
                err_flag = 1;
                break;
            }
        }
        /*check for error*/
        if(err_flag){
            continue;
        }
        element[j] = 0; /*null terminator*/
        st[nStudents].GPA = atof(element); /*convert string to it's float value*/
        /*check that it's a valid GPA value*/
        if(st[nStudents].GPA > 4){
            ERROR("Line %hu Roll Number %d GPA > 4.0\n", l, st[nStudents].roll);
            continue;
        }

        /*check for incomplete data*/
        if(!line[i]){
            ERROR("Line %hu Roll Number %d Incomplete entry\n", l, st[nStudents].roll);
            continue;
        }

        /*skip white spaces*/
        while (line[i] == ' ')
        {
            i++;
        }

        /*5. read courses*/
        j = 0, k = 0;
        while (line[i] && j < MAX_COURSES)
        {
            /*read course id number j*/
            st[nStudents].cid[j] = 0;
            while(line[i] != ' '  && line[i]){
                if(line[i] >= '0' && line[i] <= '9'){
                    st[nStudents].cid[j] *= 10;
                    st[nStudents].cid[j] += (line[i++] - '0');
                }else{
                    ERROR("Line %hu Roll Number %d Course ID must be a positive integer value\n", l, st[nStudents].roll);
                    err_flag = 1;
                    break;
                }                
            }
            if(err_flag)
                break;
            /*check for uniqueness of cid*/
            for(k = 0; k < j; k++){
                if(st[nStudents].cid[k] == st[nStudents].cid[j]){
                    ERROR("Line %hu Roll Number %d Duplicate Course ID %d \n", l, st[nStudents].roll,st[nStudents].cid[j]);
                    err_flag = 1;
                    break;
                }
            }
            if(err_flag)
                break;
            j++; /*nCourses*/
            /*skip white spaces*/
            while (line[i] == ' ')
            {
                i++;
            }
        }
        if(err_flag)
            continue;
        /*skip white spaces*/
        while (line[i] == ' ')
        {
            i++;
        }
        if(j == MAX_COURSES && line[i] ){
            ERROR("Line %hu Roll Number %d Number of courses > %u\n", l, st[nStudents].roll,MAX_COURSES);
            continue;
        }
        if(j < MIN_COURSES){
            ERROR("Line %hu Roll Number %d Number of courses < %d\n", l, st[nStudents].roll,MIN_COURSES);
            continue;
        }
        st[nStudents].cid[j] = -1; /*end of courses*/
        INFO("Line %hu Roll Number %d saved successfully\n",l,st[nStudents++].roll);
    }
    fclose(file);

    tot_s();
}

void add_student_manually(){
    /*helpfull vars*/
    uint8_t i; /*iterators*/

    DPRINTF("Add the Student Details\n");
    DPRINTF("----------------------------\n");
    /*1. get roll number*/
    DPRINTF("Enter the Roll Number: ");
    if(!scanf("%d",&st[nStudents].roll) || st[nStudents].roll < 0){ /* non-numeric or negative roll number*/
        ERROR("Roll number must be a positive Integer value\n");
        return;
    }else if(chk_roll_no(st[nStudents].roll) >= 0){ /*duplicated roll num*/
        ERROR("Roll number is already taken\n");
        return;
    }
    /*2. get fname*/
    DPRINTF("Enter the first name of student: ");
    scanf("%s",st[nStudents].fname);
    /*3. get lname*/
    DPRINTF("Enter the last name of student: ");
    scanf("%s",st[nStudents].lname);
    /*4. get GPA*/
    DPRINTF("Enter the GPA you obtained: ");
    if(!scanf("%f",&st[nStudents].GPA)){
        ERROR("Non numeric GPA\n");
        return;
    }else if(st[nStudents].GPA < 0 || st[nStudents].GPA > 4){
        ERROR("GPA must be [0.0, 4.0]\n");
        return ;
    }
    /*5. get courses*/
    DPRINTF("Enter the course ID of each course at least %d and upto %d courses (enter any negative number to exit)\n",MIN_COURSES,MAX_COURSES);
    for(i = 0; i < MAX_COURSES; i++){
        DPRINTF("Course %d id: ",i+1);
        if(!scanf("%d",&st[nStudents].cid[i])){
            ERROR("Course ID number must be an integer value\n");
            i--;
        }else if(st[nStudents].cid[i] < 0)
            break;
        else if(get_course_index(nStudents,st[nStudents].cid[i]) < i){
            ERROR("Duplicated course ID!!\n");
            i--;
        }
    }
    if(i < MIN_COURSES){
        ERROR("You must enroll in at least %d courses\n", MIN_COURSES);
    }else{
        nStudents++;
        INFO("Student Details is added Successfully\n");
        tot_s();
    }
}

void find_rl(){
    sint32_t roll;
    DPRINTF("Enter the Roll Number of the student: ");
    if(!scanf("%ld",&roll) || roll < 0){
        ERROR("Roll Number must be Positive Integer Value.\n");
    }else if((roll = chk_roll_no(roll))< 0){
        ERROR("Roll Number not found\n");
    }else{
        DPRINTF("The Students Details are\n");
        print_Student_Info(roll);
    }
}

void find_fn(){
    char fname[50];
    uint32_t i, counter = 0;
    DPRINTF("Enter the First Name of the student: ");
    scanf("%s",fname);
    for (i = 0; i < nStudents; i++)
    {
        if(!strcmp(fname,st[i].fname)){
            DPRINTF("The Students Details are\n");
            DPRINTF("=========================\n");
            print_Student_Info(i);
            counter++;
        }
    }
    if(!counter){
        ERROR(" First name %s not found\n",fname);
    }
}

void find_c(){
    sint32_t cid;
    uint32_t i, j, counter = 0;
    DPRINTF("Enter the Course ID: ");
    if(!scanf("%ld",&cid) || cid < 0){
        ERROR("Roll Number must be Positive Integer Value.\n");
        return;
    }
    for (i = 0; i < nStudents; i++)
    {
        for (j = 0; j < MAX_COURSES && st[i].cid[j] >= 0; j++)
        { 
            if(st[i].cid[j] == cid){
                DPRINTF("The Students Details are\n");
                DPRINTF("-------------------------\n");
                print_Student_Info(i);
                counter++;
                break;
            }
        }
    }
    if(!counter){
        ERROR("Course id %ld not found\n",cid);
    }else{
        INFO("Total number of Students Enrolled: %lu\n",counter);
    }
}

void tot_s(){
    DPRINTF("----------------------------\n");
    INFO("The total number of students is %lu\n",nStudents);
    INFO("You can add upto %d Students\n",MAX_STUDENTS);
    INFO("You can add %lu more students\n",MAX_STUDENTS - nStudents);
}

void del_s(){
    sint32_t roll; 
    DPRINTF("Enter The Roll Number which you want to delete: ");
    if(!scanf("%ld",&roll) || roll < 0){
        ERROR("Roll Number must be Positive Integer Value.\n");
    }else if((roll = chk_roll_no(roll) ) < 0 ){
        ERROR("This Roll Number not found\n");
    }else{
        while((uint32_t)roll < nStudents - 1)
        {
            st[roll] = st[roll+1];
            roll++;
        }
        nStudents--;
        INFO("The Roll Number is removed Successfully\n");
    }
}

void up_s(){
    char choice;
    sint32_t num;
    f32_t f;
    sint32_t roll; 
    DPRINTF("Enter The Roll Number to update the entry: ");
    if(!scanf("%ld",&roll) || roll < 0){
        ERROR("Roll Number must be Positive Integer Value.\n");
    }else if((roll = chk_roll_no(roll)) < 0){
        ERROR("This Roll Number not found\n");
    }else{
        DPRINTF("What do you want to update ?\n");
        DPRINTF("1. first name\n");
        DPRINTF("2. last name\n");
        DPRINTF("3. roll no.\n");
        DPRINTF("4. GPA\n");
        DPRINTF("5. courses\n");
        DPRINTF("please, Enter your choice: ");
        choice = getchar();
        switch (choice)
        {
        case '1':
            DPRINTF("Enter the new first name: ");
            scanf("%s",st[roll].fname);
            INFO("UPDATED SUCCESSFULLY.\n");
            break;
        case '2':
            DPRINTF("Enter the new last name: ");
            scanf("%s",st[roll].lname);
            INFO("UPDATED SUCCESSFULLY.\n");
            break;
        case '3':
            DPRINTF("Enter the new roll number: ");
            if(!scanf("%ld",&num) || num < 0){
                ERROR("Roll number must be a positive integer value\n");
            }else if(chk_roll_no(num) < 0){
                st[roll].roll = num;
                INFO("UPDATED SUCCESSFULLY.\n");
            }else{
                ERROR("This roll number is already exist!!\n");
            }
            break;
        case '4':
            DPRINTF("Enter the new GPA: ");
            if(!scanf("%f",&f)){
                ERROR("GPA must be an integer value\n");
            }else if(f < 0.0f || f > 4.0){
                ERROR("GPA must be [0.0, 4.0]\n");
            }else{
                st[roll].GPA = f;
                INFO("UPDATED SUCCESSFULLY.\n");
            }
            break;
        case '5':
            DPRINTF("----------------------------\n");
            DPRINTF("1. Add\n");
            DPRINTF("2. Drop\n");
            DPRINTF("please, Enter your choice:");
            choice = getchar();
            switch (choice)
            {
            case '1':
                num = get_no_of_courses((uint32_t)roll);
                if( num == MAX_COURSES){
                    ERROR("Maximum number of courses are achieved for this student.\n");
                }else{
                    DPRINTF("Course %ld id: ",num+1);
                    if(!scanf("%d",&st[roll].cid[num]) ||st[roll].cid[num] < 0){
                        ERROR("Course id must be a positive integer value\n");
                        st[roll].cid[num] = -1;
                    }else if(get_course_index(roll,st[roll].cid[num]) < num){
                        ERROR("Roll number %d already enrolled in this course\n",st[roll].roll);
                        st[roll].cid[num] = -1; /*null terminator*/
                    }else if(num < MAX_COURSES-1){
                        st[roll].cid[num+1] = -1; /*null terminator*/
                        INFO("UPDATED SUCCESSFULLY.\n");
                    }else{
                        INFO("UPDATED SUCCESSFULLY.\n");
                    }
                }
                break;
            case '2':
                num = get_no_of_courses((uint32_t)roll);
                if( num == MIN_COURSES){
                    ERROR("Minimum number of courses are achieved for this student.\n");
                }else{
                    DPRINTF("Course id: ");
                    if(!scanf("%ld",&num) || num < 0){
                        ERROR("Course id must be a positive integer value\n");
                    }else if((num = get_course_index(roll,num)) < 0){
                        ERROR("Roll number %ld didn't enroll in this course.\n", roll);
                    }else{
                        /*delete this course*/
                        while(st[roll].cid[num] >= 0 && num < MAX_COURSES - 1){
                            st[roll].cid[num] = st[roll].cid[num+1];
                            num++;
                        }
                        st[roll].cid[num] = -1; /*null terminator*/
                        INFO("UPDATED SUCCESSFULLY.\n");
                    }
                }
                break;
            default:
                ERROR("Wrong choice.\n");
                break;
            }
        break;
        default:
            ERROR("Wrong choice.\n");
            break;
        }
    }
}

void show_s(){
    uint32_t i ;

    for ( i = 0; i < nStudents; i++)
    {
        print_Student_Info(i);
    }
    

}

void openning_Window(){
    sint16_t choice;
    while(1){
        DPRINTF("Welcome to the Student Management System\n");
        DPRINTF("Choose the task that you want to perform\n");
        DPRINTF("1. Add the Student Details Manually\n");
        DPRINTF("2. Add the Student Details From Text File\n");
        DPRINTF("3. Find the Student Details by Roll Number\n");
        DPRINTF("4. Find the Student Details by First Name\n");
        DPRINTF("5. Find the Student Details by Course ID\n");
        DPRINTF("6. Find the Total number of Students\n");
        DPRINTF("7. Delete the Student Details by Roll Number\n");
        DPRINTF("8. Update the Student Details by Roll Number\n");
        DPRINTF("9. Show all information\n");
        DPRINTF("10. To Exit\n");
        DPRINTF("Enter your choice to perform the task: ");
        if(!scanf("%hd",&choice)||choice <0){
            ERROR("Wrong Choice.\n");
        }else{
            DPRINTF("----------------------------\n");

            switch (choice)
            {
            case 1:
                add_student_manually();
                break;
            case 2:
                add_student_file2();
                break;
            case 3:
                find_rl();
                break;
            case 4:
                find_fn();
                break;
            case 5:
                find_c();
                break;
            case 6:
                tot_s();
                break;
            case 7:
                del_s();
                break;
            case 8:
                up_s();
                break;
            case 9:
                show_s();
                break;
            case 10:
                return;
            default:
                ERROR("Wrong Choice.\n");
                break;
            }
        }
        DPRINTF("Press any key to go back to the main menu ...");
        fflush(stdin); fflush(stdout);
        getch();    	
        system("cls"); /*clear the screen*/
    }
}

void print_Student_Info(uint32_t index){
    if(index<nStudents){   
        DPRINTF("The roll number is \"%d\"\n",st[index].roll);
        DPRINTF("The First name is \"%s\"\n",st[index].fname);
        DPRINTF("The Last name is \"%s\"\n",st[index].lname);
        DPRINTF("The GPA is \"%.2f\"\n",st[index].GPA);
        DPRINTF("courses IDs list= [");
        uint32_t j;
        for (j = 0; j < MAX_COURSES; j++)
        {
            if(st[index].cid[j] < 0){
                break;
            }
            if(j == 0){
                DPRINTF("%d",st[index].cid[j]);
            }else{
                DPRINTF(", %d",st[index].cid[j]);
            }
        }
        DPRINTF("]\n==============================\n");
    }else
    {
        ERROR("index out of database!!\n");
    }
}

status_T read_student_gpa(FILE* file){
    /*get student GPA*/
    if(fscanf(file,"%f",&st[nStudents].GPA) != 1){
        // Skip this line using fscanf to read and discard the rest of the line
        ERROR("Roll number %d Non numeric GPA\n",st[nStudents].roll);
        return FAIL;
    }
    if(st[nStudents].GPA < 0 || st[nStudents].GPA > 4){
        ERROR("Roll Number %d GPA must be [0.0, 4.0]\n",st[nStudents].roll);
        return FAIL;
    }
    return PASS;
}

sint32_t chk_roll_no(uint32_t roll){
    uint32_t i;
    for(i = 0 ; i < nStudents; i++){
        if((uint32_t) st[i].roll == roll){
            return i;
        }
    }
    return -1;
}

uint32_t get_no_of_courses(uint32_t index){
    uint32_t i = 0;
    while(i < MAX_COURSES){
        if(st[index].cid[i++] < 0){
            return i -1;
        }
    }
    return i;
}

sint32_t get_course_index(uint32_t st_index, uint32_t cid){
    uint32_t i;
    for (i = 0; i < MAX_COURSES && st[st_index].cid[i] >= 0; i++)
    {
        if((uint32_t)st[st_index].cid[i] == cid)
            return i;
    }
    return -1;
}

int main(){
    openning_Window();
}