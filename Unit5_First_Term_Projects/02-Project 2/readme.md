# First Term Final Project 2 / Software for Student Information Management System
## Problem Statement
Write a program to build a simple software for student information management system which can perform the following operations:
1. Store the **First name** of the student.
2. Store the **Last name** of the student.
3. Store the unique **Roll number** for every student.
4. Store the **GPA** of every student.
5. Store the **courses** registered by the student.
## Assumptions
1. Roll number must be unique positive integer value for each student
2. GPA must be a floating-point number in the interval [0.0, 4.0]
3. Each student must enroll in at least 4 courses and can enroll upto 7 courses.
4. Courses IDs are positive Integers.
5. Each course has a unique ID.
6. System must make sure that a student cannot enroll in the same course twice. 
## Approach
The idea is to form an individual functions for every operation. All the functions are unified together to form software.
1. Add Student Details From File.
2. Add Student Details Manually.
3. Find the student by the given roll number.
4. Find the student by the given first name.
5. Find the students registered in a course.
6. Count of students.
7. Delete a student.
8. Update Student.
    1. update first name
    2. update last name
    3. update roll number
    4. update GPA
    5. update courses list
        1. Add course.
        2. Drop course.
## Test
- https://drive.google.com/drive/folders/1yVz0cwWWvgmPCyiQDkhR-NqGuaJnfx4P