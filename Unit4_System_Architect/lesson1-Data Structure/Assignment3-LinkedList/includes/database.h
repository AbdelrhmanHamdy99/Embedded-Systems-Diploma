/*
 * database.h
 *
 *  Created on: Aug 27, 2024
 *      Author: AbdoHamdy
 */

#ifndef DATABASE_H_
#define DATABASE_H_
#include "Platform_types.h"

typedef struct student {
	uint32_t ID;
	char full_name[40];
	f32_t height;
}Student_T;

#define element_type Student_T

typedef struct node {
	element_type payload;
	struct node *next;
}DB_node_T;

typedef struct DB{
	DB_node_T* head;
}DB_T ;

typedef enum {
	NULL_PTRs = -10,
	INDEX_OUT_OF_DB,
	INCORRECT_ID,
	EMPTY,
	UNKNOWN_ERROR,
	LOOP,
	PASS = 0
}status_T;

status_T DB_Init(DB_T*); /*initialize the DB*/

DB_node_T* Create_node(void); /*create a node
 	 	 	 	 	 	 	 	 	 this implementation will change based on element_type*/

status_T Insert_at_beginning(DB_T*,DB_node_T*); /*insert a created node at the beginning of the DB*/
status_T Insert_at_end(DB_T*,DB_node_T*); /*insert a node at the end of the DB*/
status_T Insert_at_index(DB_T*,DB_node_T*,uint32_t); /*insert a node at a desired index "starting from 0"*/

status_T Delete_first(DB_T*, element_type*); /*delete the first node in the DB and return the deleted element*/
status_T Delete_last (DB_T*, element_type*); /*delete the last  node in the DB and return the deleted element*/
status_T Delete_from_index(DB_T*,uint32_t, element_type*); /*delete a node at a desired index and return the deleted element*/
status_T Delete_all  (DB_T*); /*delete the entire database and return the deleted element*/
status_T Delete_by_ID(DB_T*, uint32_t, element_type*); /*implementation specific to student database and return the deleted element*/

status_T Get_first   (DB_T*, element_type*); /*get the first student in the database*/
status_T Get_Middle  (DB_T*, element_type*); /*get the student at the middle. If there is an even number of students then there is
											   two students at the mid you have to return the second one*/
status_T Get_last    (DB_T*, element_type*); /*get the last student in the database*/
status_T Get_at_index(DB_T*,uint32_t, element_type*); /*get the student with its location index*/
status_T Get_Nth_node_from_end(DB_T*,uint32_t, element_type*); /*get the student number n from the end*/
status_T Get_by_ID   (DB_T*,uint32_t, element_type*); /*get the student with its ID
 	 	 	 	 	 	 	 	 	 	 	 i			mplementation change based on DB*/

uint8_t find_length_iterative(DB_node_T*);
uint8_t find_length_recursive(DB_node_T*);

status_T Reverse(DB_T* db); /*reverse database contents*/

status_T Detect_loop(DB_T*); /*detect if there is a loop in the linked list*/
status_T create_loop(DB_T*); /*a function to create a simple loop in the linked list by connecting last element with first one*/

void UI(DB_T*);
void Display(DB_T*);/*display the whole DB*/

void printElement(element_type*);
#endif /* DATABASE_H_ */
