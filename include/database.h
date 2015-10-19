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



//ICKE GENERELLA FUNKTIONER I TREE.C



//====================================



//ICKE GENERELLA FUNKTIONER FÖR TREE.C
void incr_shelf_and_tot(list *l, void *elembox, int incr);

void incr_shelf(shelf *s, int incr);
//====================================





//GENERELLA FÖR BÅDE TREE OCH LIST
bool check_shelf_used_in_tree(tree *t, void *elembox);

bool check_shelf_used(node **n, void *elembox);



bool check_used_by_item(tree *t, void *key, void *shelfloc);
//=================================

ware *ware_exists(tree *t, char *ware_name);
bool shelf_ok(tree *t, ware *w, char *shelf_loc);
void insert_ware(tree *t, ware *w, char *ware_name, char *ware_desc, int ware_price, char *ware_shelf, int ware_amount);

char *get_ware_name(ware *w);
char *get_ware_desc(ware *w);
int get_ware_price(ware *w);

shelves *get_shelves(ware *w);
elem *get_first_shelf(ware *w);
elem *get_next_shelf(elem *e);

char *get_shelf_loc(elem *e);
int get_shelf_amount(elem *e);

#endif
