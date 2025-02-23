/*
 * Utils.h
 *
 *  Created on: Feb 20, 2025
 *      Author: AbdoHamdy
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

/***************************************************************
					Generic Macros
****************************************************************/

#define RESET_BIT(reg, bit)  (reg &= ~(1<<bit))
#define SET_BIT(reg, bit)    (reg |=  (1<<bit))
#define TOGGLE_BIT(reg, bit) (reg ^=  (1<<bit))
#define READ_BIT(reg, bit)   ((reg >> bit) & 1)
/***************************************************************
					Generic definitions
****************************************************************/
typedef enum {false, true } boolean;
#define NULL				((void*)0)


#endif /* INC_UTILS_H_ */
