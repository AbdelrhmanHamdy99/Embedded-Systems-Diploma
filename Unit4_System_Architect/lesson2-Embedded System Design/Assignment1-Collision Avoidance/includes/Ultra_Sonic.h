/*
 * Ultra_Sonic.h
 *
 *  Created on: Sep 6, 2024
 *      Author: AbdoHamdy
 */

#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_

#include "State.h"
#include "Platform_types.h"

state_API(US_Read);

void US_init(void);
sint32_t random_generator(sint32_t,sint32_t);

#endif