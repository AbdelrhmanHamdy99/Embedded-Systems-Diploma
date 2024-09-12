#include "Ultra_Sonic.h"
#include "Platform_types.h"
#include "State.h"

#include <stdio.h>
#include <stdlib.h>

f32_t US_distance = 0;

void (*US_State) ();

state_API(US_Read){
    /*read distance*/
    US_distance = random_generator(45,55);
    printf("US_Read State : distance = %.1f ",US_distance);
    Distance_set(US_distance);

}

void US_init(void){
    /*initialize the US driver*/
}


sint32_t random_generator(sint32_t min, sint32_t max){
    return (rand() % (max - min + 1)) + min;
}