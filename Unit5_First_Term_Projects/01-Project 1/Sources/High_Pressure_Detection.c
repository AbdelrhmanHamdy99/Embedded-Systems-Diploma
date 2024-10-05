#include "High_Pressure_Detection.h"
#include "states.h"
#include "platform_Types.h"

/*global vars*/
static int currentPressure;
static int currentTime = 0;
static int pressureThreshold = 20;
void (*HPDetection_next_State) () = statePtr(wait_sensor); /*a pointer to the next state*/

stateAPI(wait_sensor){
    /*sequence of actions*/
    /*It's just a waiting state*/
}
stateAPI(Take_Action){
    /*sequence of actions*/
    Fire_Alarm(); /*fire alarm*/
    /*upgrade next state*/
    HPDetection_next_State = statePtr(wait_sensor);
}

void setCurrentPressure(int pressure){
    /*1. current pressure is sent from pressure sensor*/
    currentPressure = pressure;
    /*2. store current pressure in flash*/
    storePressureVal(currentPressure,currentTime);
    /*next state upgrade*/
    if(currentPressure > pressureThreshold)
        HPDetection_next_State = statePtr(Take_Action);
    currentTime++;
}

void updateHPThreshold(int new_threshold){
    pressureThreshold = new_threshold;
}