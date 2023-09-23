#ifndef Uart_H_
#define Uart_H_

#include "Platform_Types.h"

#define Uart_BASE_ADDRESS  0x101f1000
#define Uart_DDR           *((vuint32*) ((uint32*) Uart_BASE_ADDRESS))

void Uart_SendString(uint8* data);
#endif