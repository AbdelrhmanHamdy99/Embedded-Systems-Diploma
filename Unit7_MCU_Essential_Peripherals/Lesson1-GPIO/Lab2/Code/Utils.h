/*
 * Utils.h
 *
 * Created: 1/13/2025 10:32:49 PM
 *  Author: AbdoHamdy
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define RESET_BIT(reg, bit)  (reg &= ~(1<<bit))
#define SET_BIT(reg, bit)    (reg |=  (1<<bit))
#define TOGGLE_BIT(reg, bit) (reg ^=  (1<<bit))
#define READ_BIT(reg, bit)   ((reg >> bit) & 1)

#endif /* UTILS_H_ */