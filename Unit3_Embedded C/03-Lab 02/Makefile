#generic make file
#copyrights: Abdelrhman Hamdy

#=================environment variables=================#
#C Compiler
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -gdwarf-2 
#includes directories locations
INCS= -I. 
#static libraries to be linked
LIBS=
#all C Course files
SRC= $(wildcard *.c)
#all object files generated from C source files 
OBJ= $(SRC:.c=.o) 
#all assembly files
As = $(wildcard *.s) 
#all object files generated from assembly files
AsOBJ=$(As:.s=.o) 
#output file name
project_name=toggle_a_led_cortex-M3
#=================rules=================#
	#============format=============#
#target: dependencies
	#commands

#first rule executed when make is invoked
all: $(project_name).bin 
#generate binary file to be burned on the target
$(project_name).bin: $(project_name).elf 
	$(CC)objcopy.exe -O binary $< $@
	
#generate elf file that contains debugging info
$(project_name).elf: $(OBJ) $(AsOBJ) 
	$(CC)ld.exe -T linker_script.ld $(AsOBJ) $(OBJ) $(LIBS) -o $@ -Map=map_file.map
	
#generate object file from any source file
%.o: %.c 
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
#generate object file from any assembly file
%.o: %.s 
	$(CC)as.exe $(CFLAGS) $< -o $@
	
#remove all generated files 
clean_all:  
	rm *.o *.bin *.elf

#remove just output files
clean:
	rm *.bin *.hex *.elf
	
#=================symbols=================#
	#$< : dependency
	#$@ : target