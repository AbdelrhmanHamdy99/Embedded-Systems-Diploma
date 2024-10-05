#ifndef High_Pressure_Detection_H_
#define High_Pressure_Detection_H_
#include "states.h"

stateAPI(wait_sensor);
stateAPI(Take_Action);

void updateHPThreshold(int);
#endif