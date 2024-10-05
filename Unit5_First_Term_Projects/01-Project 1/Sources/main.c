#include <stdint.h>
#include <stdio.h>

#include "states.h"
#include "driver.h"
#include "Alarm.h"
#include "Flash_Mem.h"
#include "High_Pressure_Detection.h"
#include "Pressure_Sensor.h"

void setup(void);

void setup(void){
	GPIO_INITIALIZATION();
	FlashMemInit();

	PSensor_next_State = statePtr(read);
	HPDetection_next_State = statePtr(wait_sensor);
	Alarm_next_State = statePtr(Safe);
	FlashMem_next_State = statePtr(Idle);
}


int main (){
	
	setup();
	while (1)
	{
		//Implement your Design 
		(*PSensor_next_State)();
		(*HPDetection_next_State)();
		(*Alarm_next_State)();
		(*FlashMem_next_State)();
	}

}
