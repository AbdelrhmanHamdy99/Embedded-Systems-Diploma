#include "Alarm.h"
#include "states.h"
#include "platform_Types.h"
#include "driver.h"

void (*Alarm_next_State) (void) = statePtr(Safe);
int static alarmPeriod = 600000; /*consider this is equivalent to 60s*/


stateAPI(Safe){
    Set_Alarm_actuator(1); /*turn alarm off*/
}

stateAPI(Danger){
    Set_Alarm_actuator(0); /*turn alarm on*/
    Delay(alarmPeriod); /*busy waiting*/
    Set_Alarm_actuator(1); /*turn alarm off*/
    /*update nect state*/
    Alarm_next_State = statePtr(Safe);

}

void Fire_Alarm(void){
    Alarm_next_State = statePtr(Danger);
}

void updateAlarmPeriod(int new_counts){
    alarmPeriod = new_counts;
}