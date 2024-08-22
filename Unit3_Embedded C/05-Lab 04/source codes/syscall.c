#include "platform_types.h"

void* _sbrk(uint32_t increment){
	extern uint32_t _E_bss;
	extern uint32_t _heap_max;
	
	static sint8_t *heap_pointer = (sint8_t*)&_E_bss;
	sint8_t *prev_heap_pointer;
	
	if((uint32_t)(heap_pointer + increment) > (uint32_t)&_heap_max)
		return (void*) -1;
	prev_heap_pointer = heap_pointer;
	heap_pointer += increment;
	return (void*)prev_heap_pointer;
}