#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <tree.h>
#include <list.h>
#include <assert.h>
#include <database.h>
#include <tree_secret.h>
#include <list_secret.h>
#include <dbg.h>
#include <string.h>


#define Equal action == 0
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


ware * create_ware()
{
  ware *w = calloc(1, sizeof(ware));
  return w;
}

shelf *create_shelf()
{
  shelf *s = (shelf *) calloc(1, sizeof(shelf));
  return s;
}

int key_compare(void *key1, void *key2)
{
  assert(key1 && key2);

  char *str1 = (char*)key1;
  char *str2 = (char*)key2;

  log_info("key_compare", str1, "%s");
  log_info("key_compare", str2, "%s");

  assert(strlen(str1) > 0);
  assert(strlen(str2) > 0);
  
  return strcmp(str1, str2);
}



int elem_compare(void *e1, void *e2)
{
  shelf *shlf1 = (shelf*)e1;
  shelf *shlf2 = (shelf*)e2;

  assert(shlf1); 
  assert(shlf2);
  
  return key_compare(shlf1->location , shlf2->location);
}




bool check_shelf_used(node **n, char *key)
{
  check_shelf_used_ASSERT(n);

  node **current = n;
  
  if((*current))
    {
      ware *c =(ware*)((*current)->content);
      bool eleminlist = find_elem_in_list_DB(c->shelves, key);

      if (eleminlist) return true;
      
      else return check_shelf_used(&((*current)->left), key) || check_shelf_used(&((*current)->right), key); 
    }
  return false;
}



bool check_shelf_used_in_tree(tree *t, char *key)
{
  assert(t == NULL); 
  return  check_shelf_used(&(t->root), key);
}



void incr_shelf_and_tot(list *l, void *elembox, int incr)
{
  elem *e = get_elem_in_list(l, elembox);
  shelf *s = (shelf*)e->box;

  incr_shelf(s, incr);

  int *totalamount  = (int*)l->stuff;
  (*totalamount) += incr;
}



void incr_shelf(shelf *s, int incr)
{
  s->amount += incr;
}



bool check_used_by_ware(tree *t, void *key, void *shelfloc)
{
  node *mynode = get_node_in_tree(t, key);

  ware *myitem = (ware*)mynode->content;

  return find_elem_in_list(myitem->shelves, shelfloc);
}

bool find_elem_in_list_DB(list *l, char *key)
{
  return find_elem_DB(l->first, key);
}

bool find_elem_DB(elem *e, char *key)
{
  return get_elem_DB(e, key);
}

elem * get_elem_in_list_DB(list *l, char *key)
{
  return get_elem_DB(l->first, key);
}

elem * get_elem_DB(elem *e, char *key)
{
  elem *current = e;
  shelf *s = (shelf*)current->box;
  
  while (current)
    {
      int action = key_compare(s->location, key);
      
      if (Equal) return current;
      current = current->next;
    }

  return NULL;
}


//TIMS FUNKTIONER

ware *ware_exists(tree *t, char *warename)
{
  log_info("ware_exists", t, "%p");
  log_info("ware_exists", warename, "%p");
  log_info("ware_exists", warename, "%s");

  node *n = get_node_in_tree(t, warename); //warename skickas in som om det vore en 'key'.
  log_info("ware_exists", n, "%p");

  if(!n) return NULL;

  ware *w = (ware*)n->content;
  log_info("ware_exists", w, "%p");

  return w;
}

ware *get_ware_at_aux(node *n, int index, int *acc)
{
  log_info("get_ware_at_aux", n, "%p");

  log_info("get_ware_at_aux", *acc, "%d");
  log_info("get_ware_at_aux", index, "%d");

  if(*acc > index) return NULL; //might cause logical faults

  if(n->left) get_ware_at_aux(n->left, index, acc);
  
  if(index == *acc) return get_ware(n);
  else ++(*acc);

  if(n->right) get_ware_at_aux(n->right, index, acc);

  return NULL;
}

ware *get_ware_at(tree *t, int index)
{
  log_info("get_ware_at", t, "%p");
  log_info("get_ware_at", index, "%d");

  int *acc = calloc(1, sizeof(int));
  *acc = 0;
  node *root = get_root(t);

  if(!root) return NULL;

  ware *w = get_ware_at_aux(root, index, acc);
  log_info("get_ware_at", w, "%p");

  free(acc);

  return w;
}

bool shelf_ok(tree *t, ware *w, char *shelfloc)
{
  if(w) return find_elem_in_list_DB(w->shelves, shelfloc); 

  else return check_shelf_used_in_tree(t, shelfloc);
}

void insert_ware(tree *t, ware *w, char *warename, char *waredesc, int wareprice, char *shelfloc, int shelfamount)
{
  log_info("insert_ware", t, "%p");
  log_info("insert_ware", w, "%p");
  log_info("insert_ware", warename, "%s");

  log_info("insert_ware", shelfloc, "%s");
  log_info("insert_ware", shelfamount, "%d");

  if (w)
    {
      bool shelfexists = find_elem_in_list_DB(w->shelves, shelfloc);
      log_info("insert_ware", shelfexists, "%d");

      if(shelfexists)
	{
	  elem *e = get_elem_in_list_DB(w->shelves, shelfloc);
	  log_info("add_ware", e, "%p");
	  
	  incr_shelf_and_tot(w->shelves, e->box, shelfamount);       
	}
      if(!shelfexists)
	{
	  elem *e = create_elem();
	  log_info("add_ware", e, "%p");

	  insert_elem_in_list(w->shelves, e);
	  incr_shelf_and_tot(w->shelves, e->box, shelfamount);       
	}
    }
  else
    {
      node *n = create_node();
      ware *w = create_ware();
      list *l = create_list();
      elem *e = create_elem();

      log_info("insert_ware", n, "%p");
      log_info("insert_ware", w, "%p");
      log_info("insert_ware", l, "%p");
      log_info("insert_ware", e, "%p");

      n->key = strdup(warename); //TODO generate key
      n->content = w;

      w->name = strdup(warename);
      w->desc = strdup(waredesc);
      w->price = wareprice;
      w->shelves = l;

      insert_elem_in_list(l, e);

      shelf *s = create_shelf();
      log_info("insert_ware", s, "%p");
      e->box = s;

      s->location = strdup(shelfloc);
      s->amount = shelfamount;

      append_node_in_tree(t, n);
    }
}

ware *get_ware(node *n)
{
  return (ware *)get_content(n);
}

char *get_ware_name(ware *w)
{
  return w->name;
}

char *get_ware_desc(ware *w)
{
  return w->desc;
}

int get_ware_price(ware *w)
{
  return w->price;
}



list *get_list(ware *w)
{
  return w->shelves;
}


elem *get_first_shelf(ware *w)
{
  return w->shelves->first;
}


elem *get_next_shelf(elem *e)
{
  return e->next;
}


char *get_shelf_loc(elem *e)
{
  shelf *s = (shelf*)e->box;
  return s->location;
}



int get_shelf_amount(elem *e)
{
  shelf *s = (shelf*)e->box;
  return s->amount;

}


void destroy_warehouse(tree *t)
{
  //TODO implement everything
  if(t) return;

}
