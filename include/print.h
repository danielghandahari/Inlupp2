#ifndef _PRINT_H_
#define _PRINT_H_

#include <string.h>
#include <stdio.h>
#include <database.h>
#include <dbg.h>

#define STREAM_LENGTH 512

void print_incorrect_input();
void print_choice();

void print_menu();

void print_add_header();
void print_new_ware();
void print_add_or_update_shelf();
void print_ware_added();

void print_ware(ware *w);
void print_shelves(ware *w);

void print_remove_header();

void print_edit_header();

void print_warehouse_header();
void print_warehouse_empty();
void print_end_of_warehouse();
void print_index_name(int index, char *ware_name);
void print_warehouse_menu();

void print_trolley_header();

void print_exit();
#endif
