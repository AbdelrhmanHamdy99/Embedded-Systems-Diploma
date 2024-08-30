#generic make file
#copyrights: Abdelrhman Hamdy

#=================environment variables=================#
#C Compiler
CC=
CFLAGS=-g -Wall
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
project_name=inked_list
#=================rules=================#
	#============format=============#
#target: dependencies
	#commands

#first rule executed when make is invoked
all: $(project_name).exe 
	@echo "====================done===================="
	
#generate elf file that contains debugging info
$(project_name).exe: $(OBJ) $(AsOBJ) 
	$(CC)gcc.exe $(AsOBJ) $(OBJ) $(LIBS) -o $@
	
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