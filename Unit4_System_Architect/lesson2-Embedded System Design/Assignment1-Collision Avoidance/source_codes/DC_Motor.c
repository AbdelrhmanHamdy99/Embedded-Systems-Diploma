#include "DC_Motor.h"
#include "Platform_types.h"
#include <stdio.h>

f32_t DC_Motor_Old_Speed = 0;
f32_t DC_Motor_New_Speed = 0;
void (*DC_Motor_State) ();

state_API(Motor_Saturate){
    /*do the required action*/
    printf("Motor_Saturate State : speed = %2lu\n",(uint32_t)DC_Motor_Old_Speed);
}
state_API(Motor_Update){
    /*do the required action*/
    DC_Motor_Old_Speed = DC_Motor_New_Speed;
    DC_Motor_State = state_ptr(Motor_Saturate);
    printf("Motor_Update   State : speed = %2lu\n",(uint32_t)DC_Motor_Old_Speed);

}

void DC_Motor_Init(void){
    /*initialize Motor driver*/
}

void Speed_set(f32_t speed){
    printf("->->->-> Speed_set(%2lu) ->->->-> ", (uint32_t)speed);
    DC_Motor_New_Speed = speed;
    if(DC_Motor_New_Speed != DC_Motor_Old_Speed)
        DC_Motor_State = state_ptr(Motor_Update);
    else
        DC_Motor_State = state_ptr(Motor_Saturate);

}
