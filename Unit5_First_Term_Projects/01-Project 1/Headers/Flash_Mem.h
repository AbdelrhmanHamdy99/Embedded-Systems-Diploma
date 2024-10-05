#ifndef FLASH_MEM_
#define FLASH_MEM_
#include "states.h"

void FlashMemInit(void);

stateAPI(Idle);
stateAPI(store);
#endif