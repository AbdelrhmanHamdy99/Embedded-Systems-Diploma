/*
 * State.h
 *
 *  Created on: Sep 6, 2024
 *      Author: AbdoHamdy
 */

#ifndef STATE_H_
#define STATE_H_
#include "Platform_types.h"
typedef enum {
    Motor_Saturate,
    Motor_Update
} Motor_t;

typedef enum {
    US_Read
} US_t;

typedef enum {
    CA_Waiting,
    CA_Driving
} CA_t;

#define state_API(state_name) void ST_##state_name (void)
#define state_ptr(state_name) ST_##state_name

/*Modules connectors*/
void Distance_set(f32_t);
void Speed_set(f32_t);
#endif