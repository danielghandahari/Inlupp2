#ifndef __DATABASE__
#define __DATABASE__



typedef struct _ware_ ware;

typedef struct _shelf_ shelf;
typedef struct _sum_ sum;



//ICKE GENERELLA FUNKTIONER I TREE.C



//====================================







//ICKE GENERELLA FUNKTIONER I TREE.C


void *increment_shelf();
//====================================





//GENERELLA FÖR BÅDE TREE OCH LIST
bool check_shelf_used_in_tree(tree *t, elem *e);

bool check_shelf_used(node **n, elem *e);

//=================================

#endif
