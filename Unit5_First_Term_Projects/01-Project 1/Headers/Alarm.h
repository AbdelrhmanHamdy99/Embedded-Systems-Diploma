#ifndef ALARM_H_
#define ALARM_H_
#include "states.h"

stateAPI(Safe);
stateAPI(Danger);

void updateAlarmPeriod(int);

#endif