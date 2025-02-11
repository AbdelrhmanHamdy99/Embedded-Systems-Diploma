/*
 * Utils.h
 *
 * Created: 1/13/2025 10:32:49 PM
 *  Author: AbdoHamdy
 */ 


#ifndef UTILS_H_
#define UTILS_H_


typedef unsigned char boolean;

#define true 1
#define false 0

#define nibble_start_position 4

#define RESET_BIT(reg, bit)  (reg &= ~(1<<bit))
#define SET_BIT(reg, bit)    (reg |=  (1<<bit))
#define TOGGLE_BIT(reg, bit) (reg ^=  (1<<bit))
#define READ_BIT(reg, bit)   ((reg >> bit) & 1)

#define WRITE_NIBBLE(reg, data, position) reg &= ~(0xF<<position);reg |=  (data << position);

#define READ_NIBBLE(reg, position) (reg |= (0xF<<position))




#endif /* UTILS_H_ */