#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tree.h>
#include <list.h>
#include <assert.h>
#include <database.h>
#include <tree_secret.h>

#define ElementOf(SHELF) &(SHELF)
#define ElementOrShelfOf(SHELF) (ElementOf(SHELF) == NULL || SHELF == NULL)
#define check_shelf_used_ASSERT(NODE) ware *emptylistptr =(ware*)((*NODE)->content); \
  assert((emptylistptr || emptylistptr->shelves || emptylistptr->shelves->first))




//ICKE-GENERELLA STRUCTAR FÖR TREE.C
struct _ware_
{
  char *name;
  char *desc;
  int price;

  list *shelves;
};
//==================================


//ICKE-GENERELLA STRUCTAR FÖR LIST.C

struct _shelf_
{
  char *location;
  int amount;
};

struct _sum_
{
  int totalmount;
};
//===================================





int key_compare(void *key1, void *key2)
{
  char *str1 = (char*)key1;
  char *str2 = (char*)key2;

  assert(strcmp(key1, "") == 0);
  assert(strcmp(key2, "") == 0);
  
  return strcmp(str1, str2);
}



int elem_compare(void *e1, void *e2)
{
  shelf *shlf1 = (shelf*)e1;
  shelf *shlf2 = (shelf*)e2;

  assert(ElementOrShelfOf(shlf1)); 
  assert(ElementOrShelfOf(shlf2));
  
  return key_compare(shlf1->location , shlf2->location);
}



bool check_shelf_used(node **n, void *elembox)
{
  check_shelf_used_ASSERT(n);

  node **current = n;
  
  if((*current))
    {
      ware *c =(ware*)((*current)->content);
      bool eleminlist = find_elem_in_list(c->shelves, elembox);

      if (eleminlist) return true;
      
      else return check_shelf_used(&((*current)->left), elembox) || check_shelf_used(&((*current)->right), elembox); //SKARV, KOLLAR DEN INTE BA VÄNSTER?;   
    }
  return false;
}


bool check_shelf_used_in_tree(tree *t, void *elembox)
{
  assert(t == NULL); 
  return  check_shelf_used(&(t->root), elembox);
}

void incr_shelf_and_tot(list *l, void *elembox, int incr)
{
  elem *e = get_elem_in_list(l, elembox);
  shelf *s = (shelf*)e->box;

  incr_shelf(s, incr);

  int totalamount  = (int)l->stuff;
  totalamount += incr;
}

  
void incr_shelf(shelf *s, int incr)
{
  s->amount += incr;
}


bool check_used_by_item(tree *t, void *key, void *shelfloc)
{
  node *mynode = get_node_in_tree(t, key);

  ware *myitem = (ware*)mynode->content;

  return find_elem_in_list(myitem->shelves, shelfloc);
}



