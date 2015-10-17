#ifndef __IO_H__
#define __IO_H__

#include <read.h>
#include <print.h>

#include <database.h>
#include <tree.h>
#include <list.h>

#include <stdbool.h>

void print_menu();

char get_menu_choice();

void add_ware();
void remove_ware();
void edit_ware();
void print_warehouse();
void pack_trolley();
void exit_program(bool *exit);

#endif
