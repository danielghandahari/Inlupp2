IDIR	=../include
CC	=gcc
CFLAGS 	=-Wall -std=c11 -ggdb -I$(IDIR)
CFILE	=database.c io.c list.c main.c menu.c read.c tree.c print.c

OUT	=inlupp2

$(OUT):$(CFILE)
	@echo "##\tMake:\tCompiling $@"
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo "##\tMake:\tCleaning up waste."
	@rm -f -r ../*/*~ ../*/*# ../*/*/*~ ../*/*/*#

run:inlupp2
	@rm -f inlupp2_stderr
	@touch inlupp2_stderr
	@echo "##\tMake:\tRunning file.\n##\n"
	@./$^

double_hash:
	@echo "##"

rm_out:
	@rm -f $(OUT)

all:double_hash rm_out $(OUT) clean run
