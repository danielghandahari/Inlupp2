IDIR	=../include
ODIR	=.obj
CC	=gcc

CFLAGS 	=-Wall -std=c11 -ggdb -Wextra -Werror -Wfatal-errors -I$(IDIR)

FILE	= database io list main menu read tree print trolley

DEPS 	= $(pussubst %,$(IDIR)/%.h,$(FILE))
OBJ 	= $(patsubst %,$(ODIR)/%.o,$(FILE))

OUT	=inlupp2

$(ODIR)/%.o:%.c $(DEPS)
	@echo "## Make\tCompiling $@."
	@$(CC) $(CFLAGS) -c -o $@ $<

$(OUT):$(OBJ)
	@echo "## Make\tCompiling $@."
	@$(CC) $(CFLAGS) -o $@ $^

clean:
	@echo "## Make\tCleaning up waste."
	@rm -fr ../*/*~
	@rm -fr ../*/*#
	@rm -fr ../*/*.dSYM
	@rm -fr ../*/*.DS_Store

run:$(OUT)
	@rm -f inlupp2_stderr
	@touch inlupp2_stderr
	@echo "## Make\tRunning file."
	@./$^

all:$(OUT) clean
