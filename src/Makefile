IDIR	=../include
ODIR	=obj
CC	=gcc

CFLAGS 	=-Wall -std=c11 -ggdb -Wextra -Werror -Wfatal-errors -I$(IDIR)

FILE	= database io list main menu read tree print trolley

DEPS 	= $(pussubst %,$(IDIR)/%.h,$(FILE))
OBJ 	= $(patsubst %,$(ODIR)/%.o,$(FILE))

OUT	=inlupp2

$(ODIR)/%.o:%.c $(DEPS)
	@echo "##\tMake\tCompiling $@"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OUT):$(OBJ)
	@echo "##\tMake\tCompiling $@"
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo "##\tMake\tCleaning up waste."
	@rm -fr ../*/*~
	@rm -fr ../*/*#
	@rm -fr ../*/*.dSYM
	@rm -fr ../*/*.DS_Store

run:$(OBJ)
	@rm -f inlupp2_stderr
	@touch inlupp2_stderr
	@echo "##\n##\tMake:\tRunning file.\n##\n##\n"
	@./$^

all:$(OUT) clean
