 /**
 * @file database.h
 * @author Daniel Ghandahari and Tim Svensson
 * @brief Header file for the database
 *
 */


#ifndef __DATABASE__
#define __DATABASE__

#include <stdbool.h>

typedef struct _tree_ tree;
typedef struct _ware_ ware;

typedef struct _shelves_ shelves;
typedef struct _shelf_ shelf;
typedef struct _list_ list;
typedef struct _elem_ elem;
typedef struct _node_ node;
typedef struct _sum_ sum;


/**
 * @brief returns a pointer to a ware, allocated on the heap
 */
ware * create_ware();   


/**
 * @brief increments 
 */
void incr_shelf_and_tot(list *l, char *key, int incr);

void incr_shelf(shelf *s, int incr);




bool find_elem_in_list_DB(list *l, char *key);

bool find_elem_DB(elem *e, char *key);



elem * get_elem_DB(elem *e, char *key);

elem * get_elem_in_list_DB(list *l, char *key);



bool check_shelf_used_in_tree(tree *t, char *key);   

bool check_shelf_used(node **n, char *key);  



bool check_used_by_ware(tree *t, void *key, char *shelfloc);





ware *ware_exists(tree *t, char *ware_name);
ware *get_ware_at(tree *t, int index);
ware *get_ware_at_aux(node *n, int index, int *acc);
bool shelf_ok(tree *t, ware *w, char *ware_shelf);
void insert_ware(tree *t, ware *w, char *ware_name, char *ware_desc, int ware_price, char *ware_shelf, int ware_amount);

char *get_ware_name(ware *w);
char *get_ware_desc(ware *w);
int get_ware_price(ware *w);

list *get_list(ware *w);
elem *get_first_shelf(ware *w);
elem *get_next_shelf(elem *e);

char *get_shelf_loc(elem *e);
int get_shelf_amount(elem *e);


ware *get_ware(node *n);



void destroy_warehouse(tree *t);

void destroy_warehouse_subtree(node **n);

void destroy_string(char *c);

void destroy_list_DB(list *l);

void destroy_ware(ware *w);

void destroy_node_DB(node *n);

#endif
