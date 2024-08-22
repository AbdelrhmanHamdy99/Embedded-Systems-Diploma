/*Linker_script for cortex-m3
by: Abdelrhman Hamdy */

ENTRY(Reset_Handler) /*info for the debugger*/

MEMORY {
	flash (rx) : o = 0x08000000, l = 128k /*read, execute*/
	sram (rwx) : o = 0x20000000, l = 20k  /*read, write, execute*/
}

SECTIONS {
	.text : { 
		*(.vector*)   /*.vector, .vectors, or .vector_table*/
		*(.text)
		*(.text.*)
		*(.rodata)
		*(.rodata.*)
		. = ALIGN(4); /*alignment is important to start next section at
					  an address multiple of 4*/
		_E_text = .;  /*address of the end of .text section which is the
					  also the address of the start of data section in 
					  flash. this symbol will be used by startup code in 
					  copying .data from flash to ram*/
	} > flash /*contain all sections that would remain in the flashin 
			  a sorted manner the most important thing is that .vector 
			  section must be in address 0x08000000 as in datasheet. */
	
	.data : {
		_S_data = .; /*start of .data section in sram*/
		*(.data)
		*(.data.*)
		. = ALIGN(4);
		_E_data = .; /*end of .data section in sram*/
	} > sram AT> flash /*loaded in the flash at burning time and copied
					   from flash to sram at running time by startup code*/
	
	.bss : {
		_S_bss = .;
		*(.bss)
		*(.bss*)
		*(COMMON) /*uninitialized global variables*/
		. = ALIGN(4);
		_E_bss = .;
	} > sram /*not loaded in the flash at burnning time but created and 
			 initialized to zero in sram at running time by startup code*/
	. = . + 1024 * 4; /*heap size = 4k*/
	. = ALIGN(4);
	_heap_max = .;
	
	. = . +1024; /*size of stack = 1k*/
	. = ALIGN(4);
	_stack_top = .;   /*top of stack to initialize sp in startup code*/
}