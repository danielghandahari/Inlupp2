#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tree.h>
#include <list.h>
#include <database.h>

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
  char* location;
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
  return strcmp(str1, str2);
}



int elem_compare(void *e1, void *e2)
{
  shelf *s1 = (shelf*)e1;
  shelf *s2 = (shelf*)e2;
  return strcmp(s1->location , s2->location);
}




bool check_shelf_used(node **n, elem *e)
{
  while((*n) != NULL)
    {
      assert((*n)->content == NULL); //SKA JAG ENS HA/(VARA DEFENSIV?)?
      assert((*n)->content == NULL); //SKA JAG ENS HA/(VARA DEFENSIV?)?
      ware *c =(ware*)((*n)->content);
      bool eleminlist = check_elem_in_list(c->shelves, e);

      bool checkleft = check_shelf_used(&((*n)->left), e);
      bool checkright = check_shelf_used(&((*n)->right), e);
    

  
      if (eleminlist) return true;
      else return checkleft || checkright; //SKARV, KOLLAR DEN INTE BA VÄNSTER?;
      
    }
  return false;
}


bool check_shelf_used_in_tree(tree *t, elem *e)
{
  if(t == NULL); //SKA JAG ENS HA/(VARA DEFENSIV?)?
  return  check_shelf_used(&(t->root), e);
}





