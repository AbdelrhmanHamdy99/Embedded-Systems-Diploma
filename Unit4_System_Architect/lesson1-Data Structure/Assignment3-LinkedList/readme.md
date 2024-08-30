# Unit4 / Lesson 1 / assignment 2-Linked List
## create a simple dataBase
- DataBase is represented by a head pointer that points to first node in the dataBase.
- Each node contains **payload**, and a **pointer to the next node**.
- The **element_type** of our **payload** represents what the database is for (in our case element_type = Student_T so it's a Students dataBase).
- So, it's a generic dataBase that can be used with other applications by changing **element_type** and most of our APIs will be available as we are going explain in the comming lines

## Provide a variety of APIs such as:
### DB_Init(db)
- Simply initializes **db->head** pointer to NULL as there is no nodes yet.
### Create_node()
- Save a space in the heap for a new_node and returns pointer to this node
- Fills in **node->payload** from the user based on the **element_type**. So, it's implementation depends on **element_type** and is going to change from one application to another.
- Make **node->next** points to **NULL**.
### Insert_at_beginning(db, node)
- Insert a pre-created node into the beginning of the **db**.
- returns:
	- **NULL_PTRs** : if either db or node is NULL
	- **PASS** : if process done successfully
### Insert_at_end(db, node)
- Insert a pre-created node into the end of the **db**.
- returns:
	- **NULL_PTRs** : if either db or node is NULL
	- **PASS** : if process done successfully
### Insert_at_index(db, node,index)
- Insert a pre-created node into a specific index in the **db**.
- returns:
	- **NULL_PTRs** : if either db or node is NULL
	- **INDEX_OUT_OF_DB** : in case of index greater than size of db
	- **PASS** : if process done successfully
### Get_first(db,out)
- Get the first student in the database
- The first student is returned in **out** parameter.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **PASS** : if process done successfully 
### Get_middle(db,out)
- Use two pointers **fast, slow** to get the middle student in the database.
- If there are even nodes, then there would be two middle nodes, we need to get second middle element. 
- The middle student is returned in **out** parameter.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **PASS** : if process done successfully 
### Get_last(db,out)
- Get the last student in the database
- The last student is returned in **out** parameter.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **PASS** : if process done successfully 
### Get_at_index(db,index,out)
- Get the student located at **index = x** in the database
- The student is returned in **out** parameter.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **INDEX_OUT_OF_DB** : in case of index not exist in db
	- **PASS** : if process done successfully 
### Get_Nth_node_from_end(db,n,out)
- Use two pointers **end, prev_n** to get the student at the N^th node from end of the Linked List.	
- The student is returned in **out** parameter.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **INDEX_OUT_OF_DB** : in case of n is greater than number of nodes in the dataBase
	- **PASS** : if process done successfully 
### Get_by_ID(db,ID,out)
- Get the student that has this **ID**.	
- The student is returned in **out** parameter.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **INCORRECT_ID** : there is no student has this ID in the dataBase
	- **PASS** : if process done successfully 
### Delete_first(db,removed_student)
- Delete the first student in the database
- The removed student is returned in **removed_student** parameter to show it to the user on the screen.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **PASS** : if process done successfully  
### Delete_last(db,removed_student)
- Delete the last student in the database
- The removed student is returned in **removed_student** parameter to show it to the user on the screen.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **PASS** : if process done successfully 
### Delete_from_index(db,index,removed_student)
- Delete the student located at **index = x** in the database
- The removed student is returned in **removed_student** parameter to show it to the user on the screen.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **INDEX_OUT_OF_DB** : in case of index not exist in db
	- **PASS** : if process done successfully 
### Delete_by_ID(db,ID,removed_student)
- Delete the student with **this->ID = ID**.	
- The removed student is returned in **removed_student** parameter to show it to the user on the screen.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **INCORRECT_ID** : there is no student has this ID in the dataBase
	- **PASS** : if process done successfully 
### Delete_all(db)
- Clears the database by removing all nodes.
- returns:
	- **NULL_PTRs** : if db is NULL
	- **PASS** : if process done successfully 
### find_length_iterative(node)
- Takes a pointer to the first node in the dataBase **db->head** 
- Iterate over database node till reaching the last one.
- Returns number of records in this dataBase.
### find_length_recursive(node)
- Takes a pointer to the first node in the dataBase **db->head** 
- Recyrsively call itself using **node->next** till reaching the last node.
- Returns number of records remaining in the dataBase starting from this node till the end of the dataBase.
### Reverse(db)
- Using three pointers **prev, current, next** reverse links between database nodes.
- Returns:
	- **NULL_PTRs** : if db is NULL
	- **EMPTY** : if there is no records in the dataBase
	- **PASS** : if process done successfully
### Detect_loop(db)
- Using two pointers **fast, slow** detect if there is a loop in the database
- Returns:
	- **NULL_PTRs** : if db is NULL
	- **LOOP** : if a loop is detected
	- **PASS** : if process done successfully
### Detect_loop(db)
- A function implemented for testing purposes.
- Create a simple loop by forcing the last node to point to the first one rather than pointing to NULL.
- Returns:
	- **NULL_PTRs** : if db is NULL
	- **LOOP** : if a loop is detected
	- **PASS** : if process done successfully
## test plan & output:
https://drive.google.com/drive/folders/1xawdqgR1enGU5rNQQ8lW0jul5kEOiOGR