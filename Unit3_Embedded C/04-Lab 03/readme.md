# Unit03/Lab03
## BareMetal application for ARM Cortex-m4 to toggle the green led on GPIOF3
- write the source code to perform this job 
- Use the startup.c created in Lab02 with some more complexities
	- Define stack_top without the help of the linker_script by creating the stack as an uninitialized global static array
	- Create vector_table as an array of constant pointers to functions take any arguments and return void
- Generate the object files for these .c source files
- Use Binary Utilities to analyze these relocatable images
- Write a linker_script that defines memories based on TRM, and adjust memories layout boundaries 
- Link object files together using the simple linker_script to generate .elf image, .axf image, and generate the map file
- Use Binary Utilities to analyze this elf image
- Run/Debug using keil uvision.
## Output & Code Analysis:
https://drive.google.com/drive/folders/1KNZ3hKiL99U5kqTi6pwx0Ek4_o_FKUUv