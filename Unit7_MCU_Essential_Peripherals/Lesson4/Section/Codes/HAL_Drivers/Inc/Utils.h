/*
 * Utils.h
 *
 * Created: 2/23/2025 2:28:44 PM
 *  Author: AbdoHamdy
 */ 


#ifndef UTILS_H_
#define UTILS_H_
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


#endif /* UTILS_H_ */