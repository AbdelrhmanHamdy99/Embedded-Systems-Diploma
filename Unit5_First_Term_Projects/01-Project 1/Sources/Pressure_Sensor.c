#include "states.h"
#include "Pressure_Sensor.h"
#include "driver.h"
/*global vars*/
static int current_Pressure;
void (* PSensor_next_State) () = statePtr(read);

stateAPI(read){
    /*Actions*/
    current_Pressure = getPressureVal();
    
    /*send the current pressure to HPDetection block*/
    setCurrentPressure(current_Pressure); 
    
    /*update next state*/
    /*no need to update as it's only one state*/
}

