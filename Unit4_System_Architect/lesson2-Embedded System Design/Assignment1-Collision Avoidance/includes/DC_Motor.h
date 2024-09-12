/*
 * DC_Motor.h
 *
 *  Created on: Sep 6, 2024
 *      Author: AbdoHamdy
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "State.h"
#include "Platform_types.h"

state_API(Motor_Saturate);
state_API(Motor_Update);

void DC_Motor_Init(void);

#endif