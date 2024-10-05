#include "Flash_Mem.h"
#include "states.h"
#include "platform_Types.h"
#include "driver.h"
/*global vars*/
void (*FlashMem_next_State) (void) = statePtr(Idle); /*a pointer to the next state*/
int static capture_Time;
int static pressure_Captured;
void FlashMemInit(void){
    /*Future Work*/
}

stateAPI(Idle){
    /*do nothing*/
}

stateAPI(store){
    /*store readings into the predefined location in flash memory*/

    /*then go back to Idle*/
    FlashMem_next_State = statePtr(Idle);
}
void storePressureVal(int p, int t){
    capture_Time = t;
    pressure_Captured = p;
    FlashMem_next_State = statePtr(store);
}
