# Unit03/Lab02
## BareMetal application for ARM Cortex-m3 to toggle a led on GPIO_PortA_Pin13
- write the source code to perform this job 
- Write a startup.c that initialzes stack pointer, copies .data from flash to ram, creates a space for .bss section and initialize it to zeros, and finally call main function.
- Generate the object files for these .c source files
- Use Binary Utilities to analyze these relocatable images
- Write a linker_script that defines two memories "flash, and sram", and adjust memories layout boundaries 
- Link object files together using the simple linker_script to generate .elf image and generate the map file
- Use Binary Utilities to analyze this elf image
- Run/Debug using proteus.
## Output & Code Analysis:
https://drive.google.com/drive/folders/1ldWz3PUm0saW_-zJEW1n01xSKGhdz2QJ