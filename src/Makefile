# This is where the .h files live.
IDIR=../include/

# This is the C-compiler to be used
CC=gcc

# The name of the compiled program
OUT=inlupp2-make

# These are all the generic flags to be used when compiling.
# -I $(IDIR) tells the compiler to include the .h files in the $(IDIR) directory.
CFLAGS=-Wall -std=c11 -ggdb -I$(IDIR)

# This is where the .o files will live.
ODIR=obj/

# This is where our home-made libraries lives.
LDIR=../lib/


#LIBS=

_DEPS=
DEPS=$(patsubst %,$(IDIR)%,$(_DEPS))

_OBJ=database.o main.o
OBJ=$(patsubst %,$(ODIR)%,$(_OBJ))



# This...	  ...tells the compiler...
# %		- ...to do this to every file in this directory.
# $(ODIR)%.o 	- ...to use every file that ends with .o in the directory $(ODIR).
# %.c $(DEPS)	- ...that the operation depends on the file %.c and all the files in $(DEPS).

# $@		This is the macro for the left side of the ":".
# -o $@		- ...to use the left side of the ":" as the output file.
# $<		This is the macro for the first item on the right side of the ":".
# $<		- ...to use the first item on the dependacy list as the source file.

# create the objects files used for compiling
$(ODIR)%.o:%.c $(DEPS)
	@echo "##\tMake:\tCompiling$@\tusing: $^."
	@$(CC) -c -o $@ $< $(CFLAGS)



# $^ is the macro for everything on the right side of ":".
# In this context it means to use all the files in the directory $(OBJ) to make the output.

# Compiles the program
inlupp2:$(OBJ)
	@echo "##\n##\tMake:\tCompiling $@ using: $(OBJ).\n##"
	@$(CC) -o $@ $^ $(CFLAGS)

clean:
	@echo "##\tMake:\tCleaning up waste."
	@rm -f *~ *# $(ODIR)*~ $(ODIR)*# $(IDIR)*~ $(IDIR)*#

run:inlupp2
	@echo "##\tMake:\tRunning file.\n##"
	@./$^

double_hash:
	@echo "##"

all: double_hash inlupp2 clean run
