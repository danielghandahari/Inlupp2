IDIR	=../include
CC	=gcc
CFLAGS 	=-Wall -std=c11 -ggdb -I$(IDIR)
CFILE	=database.c io.c list.c main.c menu.c read.c tree.c

OUT	=inlupp2

$(OUT):$(CFILE)
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

all:double_hash $(OUT) clean run
