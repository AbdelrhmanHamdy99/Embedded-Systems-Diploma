#include "Platform_types.h"
#include "CA_Algo.h"
#include "DC_Motor.h"
#include "Ultra_Sonic.h"
#include <stdlib.h>

extern void (*US_State) ();
extern void (*DC_Motor_State) ();
extern void (*CA_state)();

void setup(void){
    /*call initializaion functions*/
    DC_Motor_Init();
    US_init();
    /*initialize states for each module*/
    US_State = state_ptr(US_Read);
    DC_Motor_State = state_ptr(Motor_Saturate);
    CA_state = state_ptr(CA_Waiting);
}
int main(){
    setup();
    uint8_t i = 50; /*50 test case*/
    while (--i)
    {
        (*US_State)();
        (*CA_state)();
        (*DC_Motor_State)();
    }
    system("pause");
    return 0;
}