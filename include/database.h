#ifndef __DATABASE__
#define __DATABASE__

typedef struct _ware_ ware;

typedef struct _shelf_ shelf;
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
r
#endif
