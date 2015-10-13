IDIR	=../include
ODIR	=obj
CC	=gcc
CFLAGS 	=-Wall -std=c11 -ggdb -I$(IDIR)
_OBJ	=database.o io.o list.o main.o menu.o read.o tree.o
OBJ	=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o:%.c
	@echo "##\tMake:\tCompiling $@"
	@$(CC) $(CFLAGS) -c -o $@ $<

inlupp2:$(OBJ)
	@echo "##\tMake:\tCompiling $@"
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo "##\tMake:\tCleaning up waste."
	@rm -f -r ../*/*~ ../*/*# ../*/*/*~ ../*/*/*#

run:inlupp2
	@echo "##\tMake:\tRunning file.\n##\n"
	@./$^

double_hash:
	@echo "##"

all:double_hash inlupp2 clean run
