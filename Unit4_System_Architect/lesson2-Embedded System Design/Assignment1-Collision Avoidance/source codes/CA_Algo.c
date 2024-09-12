#include "CA_Algo.h"
#include "state.h"
#include <stdio.h>
f32_t CA_distance = 0;
const f32_t CA_threshold = 50;
f32_t CA_speed= 0;

void (*CA_state)();
state_API(CA_Driving){
    /*Action*/
    CA_speed = 30;
    printf("CA_Driving State : distance =%.1f speed = %.1f ",CA_distance,CA_speed);
    Speed_set(CA_speed);
        
}
state_API(CA_Waiting){
    /*Action*/
    CA_speed = 0;
    printf("CA_Waiting State : distance =%.1f speed = %.2f ",CA_distance,CA_speed);
    Speed_set(CA_speed);
    
}

void Distance_set(f32_t distance){
    printf("->->->-> Distance_set(%.1f) ->->->-> ", distance);
    /*next state*/
    CA_distance = distance;
    if(CA_distance > CA_threshold)
        CA_state = state_ptr(CA_Driving);
    else
        CA_state = state_ptr(CA_Waiting);
}