#include "Uart.h"
void Uart_SendString(uint8* data){
	while(*data != '\0'){
		Uart_DDR = *(data++);
	}
}