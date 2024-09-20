/*
 * database.c
 *
 *  Created on: Aug 27, 2024
 *      Author: AbdoHamdy
 */
#include "database.h"
#include "Platform_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define Dprintf(...)  	fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);

#define Dscanf(...)     fflush(stdin);\
		fflush(stdout);\
		scanf(__VA_ARGS__);

/*macro to test all APIs and functionalities*/
#define test_DB_api(fun_name,...)   switch(fun_name(__VA_ARGS__)){\
		case NULL_PTRs:\
		Dprintf("*****ERROR in %s!! there is no database at all!!*****\n",#fun_name);\
		break;\
		case INDEX_OUT_OF_DB:\
		Dprintf("*****ERROR in %s!! the entered index is out of boundaries!!*****\n",#fun_name);\
		break;\
		case INCORRECT_ID:\
		Dprintf("*****ERROR in %s!! database has no student with this ID!!*****\n",#fun_name);\
		break;\
		case EMPTY:\
		Dprintf("*****ERROR in %s!! the database is empty!!*****\n",#fun_name);\
		break;\
		case LOOP:\
		Dprintf("*****ERROR in %s!! there is a loop in the database!!*****\n",#fun_name);\
		break;\
		case PASS:\
		Dprintf("*****%s is done successfully*****\n",#fun_name);\
		flag = 1;\
		break;\
		default:\
		Dprintf("*****ERROR in %s!! Unknown error!!*****\n",#fun_name);\
		break;\
}

status_T DB_Init(DB_T* db){
	if(!db)
		return NULL_PTRs;
	db->head = NULL;
	return PASS;
} /*initialize the DB*/

DB_node_T* Create_node(void){
	/*creation of a node*/
	DB_node_T* node = (DB_node_T*) malloc(sizeof(DB_node_T));
	if(!node)
		return NULL;
	/*initialization*/
	node->next = NULL;
	Dprintf("Enter student ID: ");
	Dscanf("%lu",&node->payload.ID);
	Dprintf("Enter student Full name: ");

	Dscanf("%[^\n]",node->payload.full_name);

	Dprintf("Enter student height: ");
	Dscanf("%f",&node->payload.height);
	return node;
} /*create a node
	this implementation will change based on element_type*/

status_T Insert_at_beginning(DB_T* db,DB_node_T* node){
	if(!db || !node)
		return NULL_PTRs;
	node->next = NULL;
	if(db->head)/*there is elements in the database*/
		node->next = db->head;
	db->head = node;
	return PASS;
} /*insert a created node at the beginning of the DB*/

status_T Insert_at_end(DB_T* db,DB_node_T* node){
	DB_node_T* temp; /*a temp node to traverse th db*/
	if(!db || !node)
		return NULL_PTRs;

	node->next = NULL; /*this the last node*/
	if(!db->head){ /*empty DB*/
		db->head = node;
	}else{
		temp = db->head;
		while(temp->next){
			temp = temp->next;
		}
		temp->next = node; /*put the node at the end*/
	}
	return PASS;
} /*insert a node at the end of the DB*/

status_T Insert_at_index(DB_T* db,DB_node_T* node,uint32_t index){
	DB_node_T* temp; /*a temp node to traverse th db*/
	if(index == 0) /*Insert at beginning*/
		return Insert_at_beginning(db,node);
	if(!db || !node)
		return NULL_PTRs;
	if(!db->head) /*index > 0 but there are no nodes*/
		return INDEX_OUT_OF_DB;

	node->next = NULL; /*initially node doesn't point to any other node*/
	temp = db->head;
	while(--index && temp->next){
		temp = temp->next;
	}
	if(index) /*there are no more nodes*/
		return INDEX_OUT_OF_DB;
	node->next = temp->next; /*make the new node points to the node that was originally located in the desired place*/
	temp->next = node; /*make the previous node points to the new node*/
	return PASS;
} /*insert a node at a desired index "starting from 0"*/

status_T Delete_first(DB_T* db, element_type* removed_student){
	DB_node_T* del; /*to carry the deleted node*/
	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;
	del = db->head;
	db->head = del->next;
	/*return student contents before deletion*/
	*removed_student = del->payload;
	free(del); /*free the allocated space*/
	return PASS;
} /*delete the first node in the DB*/

status_T Delete_last (DB_T* db, element_type* removed_student){
	DB_node_T* del; /*to carry the deleted node*/
	DB_node_T* prev_del; /*to carry the node that points to the deleted node*/

	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;

	del= prev_del = db->head;
	if(!prev_del->next){ /*in case of only one node exist in the db*/
		/*return student contents before deletion*/
		*removed_student = prev_del->payload;
		free(prev_del);
		db->head = NULL;/*the db becomes empty*/
	}
	/*while there are  more nodes keep going*/
	while(del->next){
		prev_del = del;
		del = del->next;
	}
	prev_del->next = NULL; /*update the end of the db*/
	/*return student contents before deletion*/
	*removed_student = del->payload;
	free(del); /*free the allocated space*/
	return PASS;
} /*delete the last  node in the DB*/

status_T Delete_from_index(DB_T* db,uint32_t index, element_type* removed_student){
	DB_node_T* del; /*to carry the deleted node*/
	DB_node_T* prev_del; /*to carry the node that points to the deleted node*/
	if(!index)
		return Delete_first(db,removed_student);
	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;

	del= prev_del = db->head;
	while(index && del->next){
		prev_del = del;
		del = del->next;
		index--;
	}
	if(index)
		return INDEX_OUT_OF_DB;
	prev_del->next = del->next;
	/*return student contents before deletion*/
	*removed_student = del->payload;
	free(del); /*free the allocated space*/
	return PASS;
} /*delete a node at a desired index*/

status_T Delete_all  (DB_T* db){
	DB_node_T *node; /*to iterate over all nodes till reaching null*/
	DB_node_T *del; /*the node to be deleted*/
	if(!db)
		return NULL_PTRs;
	node = db->head;
	while(node){
		del = node;
		node = node->next; /*jump to next node*/
		free(del);
	}
	db->head = NULL;
	return PASS;
} /*delete the entire database*/

status_T Delete_by_ID(DB_T* db, uint32_t ID, element_type* removed_student){
	DB_node_T* del; /*to carry the deleted node*/
	DB_node_T* prev_del; /*to carry the node that points to the deleted node*/

	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;

	prev_del = db->head;
	/*first element is the desired student*/
	if(prev_del->payload.ID == ID){
		db->head = prev_del->next;
		/*return student contents before deletion*/
		*removed_student = prev_del->payload;
		free(prev_del); /*free rhe allocated space*/
		return PASS;
	}
	del = prev_del->next;
	/*keep going till either db finished or student found*/
	while(del->next && del->payload.ID != ID){
		prev_del = del;
		del = del->next;
	}
	if(del->payload.ID != ID)
		return INCORRECT_ID;/*no more nodes and ID not found*/
	prev_del->next = del->next;
	/*return student contents before deletion*/
	*removed_student = del->payload;
	free(del);/*free the allocated space*/
	return PASS;
} /*implementation specific to student database*/

status_T Get_first   (DB_T* db, element_type* out){
	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;
	*out = db->head->payload;
	return PASS;
} /*get the first student in the database*/

status_T Get_middle  (DB_T* db, element_type *out){
	DB_node_T *fast; /*step = 2*/
	DB_node_T *slow; /*step = 1*/
	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;
	fast = slow = db->head;
	while(fast && fast->next){
		slow = slow->next;
		fast= fast->next->next; 
	}
	/*slow represents the node at the middle*/
	*out = slow->payload;
	return PASS;
}

status_T Get_last    (DB_T* db, element_type *out){
	DB_node_T *temp;
	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;
	temp = db->head;
	while(temp->next){
		temp = temp->next;
	}
	/*return desired payload*/
	*out= temp->payload;
	return PASS;
} /*get the last student in the database*/

status_T Get_at_index(DB_T* db, uint32_t index, element_type* out){
	DB_node_T* temp; /*to iterate till reaching the desired node*/
	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;

	temp = db->head;
	while(index-- && temp){
		temp = temp->next;
	}
	if(!temp)
		return INDEX_OUT_OF_DB;
	/*return desired payload*/
	*out = temp->payload;
	return PASS;
} /*return student located at a specific index*/

status_T Get_Nth_node_from_end(DB_T* db,uint32_t n, element_type* out){
	DB_node_T *end; /*pointer that will reach to end of the list*/
	DB_node_T *prev_n; /*desired pointer that will point to the Nth node from the back*/
	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;
	end = db->head;
	while(--n && end){
		end = end->next;
	}
	if(n)
		return INDEX_OUT_OF_DB;
	prev_n = db->head;
	while (end->next)
	{
		prev_n = prev_n->next;
		end = end->next;
	}
	
	/*return desired payload*/
	*out = prev_n->payload;
	return PASS;
} /*get the student number n from the end*/

status_T Get_by_ID   (DB_T* db, uint32_t ID, element_type* out){
	DB_node_T* temp; /*to iterate till reaching the desired node*/
	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;

	temp = db->head;
	while(temp && temp->payload.ID != ID){
		temp = temp->next;
	}
	if(!temp)
		return INCORRECT_ID;
	*out = temp->payload;
	return PASS;
} /*return a student with required ID. Implementation change based on DB*/

uint8_t find_length_iterative(DB_node_T* node){
	uint8_t sum = 0;
	while (node)
	{
		node = node->next;
		sum++;
	}
	return sum;	
}

uint8_t find_length_recursive(DB_node_T* node){
	if(!node)
		return 0;
	return 1 + find_length_recursive(node->next);
}

status_T Reverse(DB_T* db){
	DB_node_T *prev, *current, *next;
	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;
	prev = NULL, current = db->head;
	while(current){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	/*now prev points to the new head*/
	db->head = prev;
	return PASS;
}

status_T Detect_loop(DB_T* db){
	DB_node_T *fast, *slow;
	if(!db)
		return NULL_PTRs;
	fast = slow = db->head;
	while(fast && fast->next){
		slow = slow->next; /*step by 1*/
		fast = fast->next->next; /*step by 2*/
		if(slow == fast){
			return LOOP;
		}
	}
	return PASS;
}

status_T create_loop(DB_T *db){
	DB_node_T *temp; 
	if(!db)
		return NULL_PTRs;
	if(!db->head)
		return EMPTY;
	temp = db->head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = db->head;
	return PASS;
}

void UI(DB_T* db){
	DB_node_T* New_node = NULL;
	element_type student;
	uint32_t option;
	uint8_t flag = 0;
	if(!db){
		Dprintf("Invalid database!!!\n");
		return;
	}
	Dprintf("============Hello in Students DB AI============\n");
	Dprintf("What do you Want to do ?\n");
	Dprintf("1: Detect Loop\n");
	Dprintf("2: Add Student\n");
	Dprintf("3: Get A Student\n");
	Dprintf("4: Count number of students in the database\n");
	Dprintf("5: View all Database contents\n");
	Dprintf("6: Reverse database contents\n");
	Dprintf("7: Delete Student\n");
	Dprintf("8: Clear the Database\n");
	Dprintf("9: Create a loop in the database. \"for testing purposes\"\n");
	Dprintf("Enter option number: ");
	Dscanf("%lu",&option);

	system("cls");
	switch(option){
	case 1 : 
		test_DB_api(Detect_loop,db);
		break;
	case 2:
		Dprintf("============Inserting Student Data============\n");
		New_node = Create_node();
		Dprintf("\n============Student location============\n");
		Dprintf("1- Insert a student at the beginning of the database.\n");
		Dprintf("2- Insert a student at the end of the database.\n");
		Dprintf("3- Insert a student at a specific required index.\n");
		Dprintf("Enter option number: ");
		Dscanf("%lu",&option);
		switch(option){
		case 1:
			test_DB_api(Insert_at_beginning,db,New_node);
			break;
		case 2:
			test_DB_api(Insert_at_end,db,New_node);
			break;
		case 3:
			Dprintf("\nInsert the index: ");
			Dscanf("%lu",&option);
			test_DB_api(Insert_at_index,db,New_node,option);
			break;
		default:
			Dprintf("Error Invalid Choice!! Please try again Later!\n");
			break;
		}
		break;
	case 3:
		Dprintf("============Getting Student Data============\n");
		Dprintf("1- Get the first student\n");
		Dprintf("2- Get the midle student\n");
		Dprintf("3- Get the last student\n");
		Dprintf("4- Get by index\n");
		Dprintf("5- Get node number n from the end.\n");
		Dprintf("6- Get by ID\n");
		Dprintf("Enter option number: ");
		Dscanf("%lu",&option);
		switch(option){
		case 1:
			test_DB_api(Get_first,db,&student);
			break;
		case 2:
			test_DB_api(Get_middle,db,&student);
			break;
		case 3:
			test_DB_api(Get_last,db,&student);
			break;
		case 4:
			Dprintf("Enter Student Index: ");
			Dscanf("%lu",&option);
			test_DB_api(Get_at_index,db,option,&student);
			break;
		case 5:
			Dprintf("Enter n: ");
			Dscanf("%lu",&option);
			test_DB_api(Get_Nth_node_from_end,db,option,&student);
			break;
		case 6:
			Dprintf("Enter Student ID: ");
			Dscanf("%lu",&option);
			test_DB_api(Get_by_ID,db,option,&student);
			break;
		default:
			Dprintf("Error Invalid Choice!! Please try again Later!\n");
			break;
		}
		if(flag){
			printElement(&student);
			flag = 0;
		}
	break;
	case 4:
	/*test both iterative and recursive*/
		option = find_length_iterative(db->head);
		printf("length from iterative API = %lu\n",option);
		find_length_recursive(db->head);
		printf("length from recursive API = %lu\n",option);
		break;
	case 5:
		Display(db);
		break;
	case 6:
		test_DB_api(Reverse,db);
		break;
	case 7:
		Dprintf("============Deleting a student============\n");
		Dprintf("1- Delete the first Student\n");
		Dprintf("2- Delete the last student\n");
		Dprintf("3- Delete a student as a specific index\n");
		Dprintf("4- Delete a student with a specific ID\n");
		Dprintf("Enter option number: ");
		Dscanf("%lu",&option);
		switch(option){
		case 1:
			test_DB_api(Delete_first,db,&student);
			break;
		case 2:
			test_DB_api(Delete_last,db, &student);
			break;
		case 3:
			Dprintf("\nInsert the index: ");
			Dscanf("%lu",&option);
			test_DB_api(Delete_from_index,db,option, &student);
			break;
		case 4:
			Dprintf("\nInsert the ID: ");
			Dscanf("%lu",&option);
			test_DB_api(Delete_by_ID,db,option,&student);
			break;
		default:
			Dprintf("Error Invalid Choice!! Please try again Later!\n");
			break;
		}
		if(flag){
			printElement(&student);
			flag = 0;
		}
		break;
	case 8:
		test_DB_api(Delete_all,db);
		break;
	case 9:
		test_DB_api(create_loop,db);
		break;
	default:
		Dprintf("Error Invalid Choice!! Please try again Later\n");
		break;
	}
	Dprintf("Press enter to continue...\n");
	fflush(stdin);
	fflush(stdout);
	getchar();
	system("cls");
}

void Display(DB_T* db){
	DB_node_T* temp; /*to iterate over nodes*/
	if(!db){
		Dprintf("Invalid database!!!\n");
		return;
	}
	printf("\n============DataBase Contents============\n");
	if(!db->head){
		printf("database is Empty\n");
	}
	temp = db->head;
	while(temp){
		printElement(&(temp->payload));
		temp = temp->next;
	}
}/*display the whole DB*/

void printElement(element_type* student){
	Dprintf("Student ID : %ld\n",student->ID);
	Dprintf("Student Full Name : %s\n",student->full_name);
	Dprintf("Student Height : %f\n",student->height);
	Dprintf("_________________________________________________\n");
}


