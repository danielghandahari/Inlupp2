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

void add_ware(tree *t);
void remove_ware(tree *t);
void edit_ware(tree *t);
void print_warehouse(tree *t);
void pack_trolley(tree *t);
void exit_program(bool *exit, tree *t);

#endif
