/*startup code for cortex-m3
by: Abdelrhman Hamdy*/
#include "platform_types.h"

extern uint32_t _stack_top;/*from linker_script*/ 
extern uint32_t _E_text;   /*from linker_script*/
extern uint32_t _S_data;   /*from linker_script*/
extern uint32_t _E_data;   /*from linker_script*/
extern uint32_t _S_bss;    /*from linker_script*/
extern uint32_t _E_bss;    /*from linker_script*/


extern int main(); /*from main app*/

void Default_Handler(void);
void Reset_Handler(void);

void NMI_Handler(void)      __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)__attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SVCall_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)  __attribute__((weak, alias("Default_Handler")));
/*weak --> tells the compiler that this definition is weak and can be 
		   overriden by the user. to give the user ability to handle
		   needed faults*/
		   
/*alias--> tells the compiler that this definition is just like a prototype
		   to another definition "Default Handler" to avoid rewriting the 
		   same code and seizing another space for the same code*/
uint32_t vector_table[155] __attribute__((section(".vector_table"))) = {
	/*the given attribute tills the compiler to store this gloal
	array at a section named ".vector_table"*/
	(uint32_t) &_stack_top, /*symbols don't have a value
							they just have an address*/
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &HardFault_Handler,
	(uint32_t) &MemManage_Handler,
	(uint32_t) &BusFault_Handler,
	(uint32_t) &UsageFault_Handler,
	(uint32_t) 0, /*reserved*/
	(uint32_t) 0, /*reserved*/
	(uint32_t) 0, /*reserved*/
	(uint32_t) 0, /*reserved*/
	(uint32_t) &SVCall_Handler,
	(uint32_t) 0, /*reserved for debug*/
	(uint32_t) 0, /*reserved*/
	(uint32_t) &PendSV_Handler,
	(uint32_t) &SysTick_Handler 
	/*and so on ....*/
	/*till the end of the vector table*/
};

void Reset_Handler(void){
	/*copy .data section from rom to ram*/
	/*we are using sint8_t to copy data byte by byte to 
	avoid copying of unrelated bytes due to unalignment*/
	sint8_t* S_data_rom = (sint8_t*) &_E_text;
	sint8_t* S_data_ram = (sint8_t*) &_S_data;
	uint32_t size = (sint8_t*) &_E_data - S_data_ram;
	
	uint32_t i; /*iterator*/
	for(i = 0; i < size ; i++){
		*(S_data_ram++) = *(S_data_rom++);
	}
	/*create and initialise .bss section*/
	sint8_t* S_bss = (sint8_t*) &_S_bss;
	size = (sint8_t*) &_E_bss - S_bss;
	for(i = 0; i < size ; i++){
		*(S_bss++) = 0;
	}
	/*call main*/
	main();
	while(1); /*in case of return from main*/
}

void Default_Handler(void){
	Reset_Handler();
}