IDIR	=../include
ODIR	=obj
CC	=gcc
CFLAGS 	=-Wall -std=c11 -ggdb -I$(IDIR)
_OBJ	=database.o io.o list.o main.o menu.o read.o tree.o
OBJ	=$(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o:%.c
	@echo "##\tMake:\tCompiling: $@\n##\t\tUsing: $^"
	@$(CC) -c -o $@ $< $(CFLAGS)

inlupp2:$(OBJ)
	@echo "##\n##\tMake:\tCompiling: $@\n##\t\tUsing: $(OBJ).\n##"
	@$(CC) -o $@ $^ $(CFLAGS)

clean:
	@echo "##\tMake:\tCleaning up waste."
	@rm -f -r ../*/*~ ../*/*# ../*/*/*~ ../*/*/*#

run:inlupp2
	@echo "##\tMake:\tRunning file.\n##"
	@./$^

double_hash:
	@echo "##"

all:double_hash inlupp2 clean run
