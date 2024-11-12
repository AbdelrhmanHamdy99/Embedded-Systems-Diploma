#generic make file
#copyrights: Abdelrhman Hamdy

#=================environment variables=================#
#C Compiler
CC=
CFLAGS= -g -Wall -Werror
#includes directories locations
INCS= -I./Headers/
#static libraries to be linked
LIBS=
#source and object directories
SRC_DIR=./Sources
OBJ_DIR=./object_files
OUTPUT_DIR=./Output
#all C source files in the src directory
SRC= $(wildcard $(SRC_DIR)/*.c)
#all object files generated from C source files to be stored in object_files
OBJ= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
#all assembly files in the src directory
As = $(wildcard $(SRC_DIR)/*.s)
#all object files generated from assembly files to be stored in object_files
AsOBJ=$(patsubst $(SRC_DIR)/%.s, $(OBJ_DIR)/%.o, $(As))
#output file name
project_name=final_project_2
#=================rules=================#
	#============format=============#
#target: dependencies
	#commands

#first rule executed when make is invoked
all: $(OUTPUT_DIR)/$(project_name).exe 
	@echo "====================done===================="
	
#generate binary file to be burned on the target
$(OUTPUT_DIR)/$(project_name).exe: $(OBJ) $(AsOBJ) $(OUTPUT_DIR)
	$(CC)gcc.exe $(AsOBJ) $(OBJ) $(LIBS) -o $@ 
	
#generate object file from any source file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	
#generate object file from any assembly file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(CC)as.exe $(CFLAGS) $< -o $@

#create the object_files and Output directories if they don't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

#remove all generated files 
clean_all:  
	rm -r $(OBJ_DIR) $(OUTPUT_DIR)

#remove just object files
clean:
	rm -r $(OBJ_DIR)

#=================symbols=================#
	#$< : dependency
	#$@ : target