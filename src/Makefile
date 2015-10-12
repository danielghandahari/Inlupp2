IDIR=../include/ 	# This is where the .h files live.
ODIR=obj/ 		# This is where the .o files will live.
LDIR=../lib/ 		# This is where our home-made libraries lives.
TDIR=tests/		# all test files

CC=gcc			# This is the C-compiler to be used

# these are all the generic flags to be used when compiling.
# -I $(IDIR) tells the compiler to include the .h files in the $(IDIR) directory.
CFLAGS=-Wall -std=c11 -ggdb -I$(IDIR)

# this is where all the .h files lives
_DEPS=database.h io.h menu.h tree.h list.h read.h
DEPS=$(patsubst %,$(IDIR)%,$(_DEPS))

# creates the file paths to all .o files
_OBJ=database.o io.o main.o menu.o tree.o list.o read.o
OBJ=$(patsubst %,$(ODIR)%,$(_OBJ))



# This...	  ...tells the compiler...
# %		- ...to do this to every file in this directory.
# $(ODIR)%.o 	- ...to use every file that ends with .o in the directory $(ODIR).
# %.c $(DEPS)	- ...that the operation depends on the file %.c and all the files in $(DEPS).

# $@		This is the macro for the left side of the ":".
# -o $@		- ...to use the left side of the ":" as the output file.
# $<		This is the macro for the first item on the right side of the ":".
# $<		- ...to use the first item on the dependacy list as the source file.

$(ODIR)%.o:%.c $(DEPS)	# create the objects files used for compiling
	@echo "##\tMake:\tCompiling: $@\n##\t\tUsing: $^."
	@$(CC) -c -o $@ $< $(CFLAGS)

# $^ is the macro for everything on the right side of ":".
# In this context it means to use all the files in the directory $(OBJ) to make the output.

inlupp2:$(OBJ)		# Compiles the program
	@echo "##\n##\tMake:\tCompiling: $@ Using:\n##\t\t$(OBJ).\n##"
	@$(CC) -o $@ $^ $(CFLAGS)

clean:			# Cleans all directories of waste files
	@echo "##\tMake:\tCleaning up waste."
	@rm -f -r ../*/*~ ../*/*# ../*/*/*~ ../*/*/*#

run:inlupp2
	@echo "##\tMake:\tRunning file.\n##"
	@./$^

double_hash:
	@echo "##"

all: double_hash inlupp2 clean run
