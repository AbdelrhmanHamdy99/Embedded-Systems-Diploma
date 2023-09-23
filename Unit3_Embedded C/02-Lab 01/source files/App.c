#include "Platform_Types.h"
#include "Uart.h"

uint8 data[100] = "Learn-in-depth: <Abdelrhman Hamdy>";


void main(void){
	Uart_SendString(data);
}