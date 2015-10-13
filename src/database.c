#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tree.h>
#include <list.h>
#include <assert.h>

#include <database.h>

#define ElementOf(SHELF) &(SHELF)
#define ElementOrShelfOf(SHELF) (ElementOf(SHELF) || SHELF)
#define check_shelf_used_ASSERT(NODE) ware *emptylistptr =(ware*)((*NODE)->content); \
  assert((*NODE)->emptylistptr || (*NODE)->emptylistptr->shelves || (*NODE)->emptylistptr->shelves->first  == NULL)




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

  //assert(strcmp(key1, "") == 0);
  //assert(strcmp(key2, "") == 0);
  
  return strcmp(str1, str2);
}



int elem_compare(void *e1, void *e2)
{
  shelf *shlf1 = (shelf*)e1;
  shelf *shlf2 = (shelf*)e2;

  //assert(ElementOrShelfOf(shlf1) == NULL); 
  //assert(ElementOrShelfOf(shlf2) == NULL);
  
  return key_compare(shlf1->location , shlf2->location);
}



bool check_shelf_used(node **n, elem *e)
{
  //check_shelf_used_ASSERT(n);

  node **current = n;
  
  if((*current) != NULL)
    {

      ware *c =(ware*)((*current)->content);
      bool eleminlist = check_elem_in_list(c->shelves, e);

      bool checkleft = check_shelf_used(&((*current)->left), e);
      bool checkright = check_shelf_used(&((*current)->right), e);
    

  
      if (eleminlist) return true;
      else return checkleft || checkright; //SKARV, KOLLAR DEN INTE BA VÄNSTER?;
      
    }
  return false;
}


bool check_shelf_used_in_tree(tree *t, elem *e)
{
  assert(t == NULL); 
  return  check_shelf_used(&(t->root), e);
}





