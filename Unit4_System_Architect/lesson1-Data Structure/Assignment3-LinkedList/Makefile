#generic make file
#copyrights: Abdelrhman Hamdy

#=================environment variables=================#
#C Compiler
CC=
CFLAGS=-g -Wall
#includes directories locations
INCS= -I./includes/
#static libraries to be linked
LIBS=
#source and object directories
SRC_DIR=./source_codes
OBJ_DIR=./object_files
#all C source files in the source codes directory
SRC= $(wildcard $(SRC_DIR)/*.c)
#all object files generated from C source files to be stored in object_files
OBJ= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
#all assembly files in the src directory
As = $(wildcard $(SRC_DIR)/*.s)
#all object files generated from assembly files to be stored in object_files
AsOBJ=$(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(As))
#output file name
project_name=inked_list
#=================rules=================#
	#============format=============#
#target: dependencies
	#commands

#first rule executed when make is invoked
all: $(project_name).exe 
	@echo "====================done===================="
	
#generate exe file
$(project_name).exe: $(OBJ) $(AsOBJ) 
	$(CC)gcc.exe $(AsOBJ) $(OBJ) $(LIBS) -o $@
	
#generate object file from any C source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
#generate object file from any assembly file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(CC)as.exe $(CFLAGS) $< -o $@

#create the object_files directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	
#remove all generated files 
clean_all:  
	rm *.o *.bin *.elf

#remove just output files
clean:
	rm *.bin *.hex *.elf
	
#=================symbols=================#
	#$< : dependency
	#$@ : target