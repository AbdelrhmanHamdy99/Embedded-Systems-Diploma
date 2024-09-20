/*
 * test_db.c
 *
 *  Created on: Aug 27, 2024
 *      Author: AbdoHamdy
 */

#include "database.h"
#include "Platform_types.h"

int main(void){
	DB_T db;
	DB_Init(&db);
	while(1)
		UI(&db);
	return 0;
}
