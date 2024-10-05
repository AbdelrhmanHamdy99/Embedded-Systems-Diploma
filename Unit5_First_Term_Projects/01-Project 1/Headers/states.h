#ifndef STATE_H_
#define STATE_H_
#include "platform_Types.h"

#define stateAPI(state) void state##_ST(void)
#define statePtr(state) state##_ST

/*define all states in our system*/
typedef enum{
    read
} PSensor_States_T;

typedef enum{
    wait_sensor,
    Take_Action
} HPDetection_States_T;

typedef enum{
    Safe,
    Danger
} Alarm_States_T;

typedef enum{
    Idle,
    store
} FlashMem_States_T;

/*states Pointers*/
extern void (*PSensor_next_State) (void);
extern void (*HPDetection_next_State) (void);
extern void (*Alarm_next_State) (void);
extern void (*FlashMem_next_State) (void);

/*Port Connectors*/
extern void setCurrentPressure(int);
extern void Fire_Alarm(void);
extern void storePressureVal(int,int);

#endif