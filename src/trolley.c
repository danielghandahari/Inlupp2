#define _GNU_SOURCE

#include <database.h>
#include <database_secret.h>
#include <trolley_secret.h>
#include <trolley.h>
#include <stdlib.h>
#include <dbg.h>
#include <stdbool.h>
#include <assert.h>

trolley * create_trolley()
{
  trolley *t = calloc(1, sizeof(trolley));
  return t;
}


int *create_tot()
{
  int *i = calloc(1, sizeof(int));
  return i;
}


bool trolley_is_empty(list *l)
{
  return l->first ? false : true;
}


int get_trolley_amount(list *l, char* key)
{
  for(elem *e = l->first; e; e = e->next)
    {
      trolley *tr = e->box;
      if(strcmp(tr->key, key) == 0) return tr->amount;
    }

  return 0;
}

int get_trolley_price(list *l)
{
  return *((int*)l->stuff);
}


void incr_amount(elem *e, int incr)
{
  trolley *t = (trolley*)e->box;
  t->amount += incr;
}



void incr_trolley_price(list *l, int incr)
{
  int *i = (int*)l->stuff;
  *i += incr;
}



int get_tot(tree *t, char *key)
{
  node *n = get_node_in_tree(t, key);
  ware *w = (ware*)n->content;

  return *((int*)w->shelves->stuff);
}



char * get_key(list *l, char *key)
{
  elem *e = get_elem_in_list_DB(l, key);

  trolley *t = (trolley*)e->box;

  return t->key;
}



int get_amount(list *l, char *key)
{
  elem *e = get_elem_in_list_DB(l, key);

  trolley *t = (trolley*)e->box;

  return t->amount;
}



void pack_trolley(tree *t, list *l, char *ware_name, int amount)
{
  if(amount <= 0) return;

  char *key = make_key(ware_name);
  elem *e = get_elem_in_list_DB(l, key);

  if(e)
    {
      incr_amount(e, amount);

      node *n = get_node_in_tree(t, key);
      ware *w = (ware*)n->content;
      int tot_price = (w->price) * amount;

      incr_trolley_price(l, tot_price);
    }
  else
    {
      elem *new_elem = create_elem();
      trolley *new_trolley = create_trolley();
      
      new_elem->box = new_trolley;
      
      new_trolley->key = strdup(key);
      new_trolley->amount = amount;

      insert_elem_in_list(l, new_elem);

      node *n = get_node_in_tree(t, key);
      ware *w = (ware*)n->content;
      int tot_price = (w->price) * amount;
      
      incr_trolley_price(l, tot_price);
    }

  if(key) free(key);
}



elem * get_elem_trolley(list *l, char *key)
{
  return get_elem_trolley_aux(l->first, key);
}



elem * get_elem_trolley_aux(elem *e, char *key)
{
  elem *current = e;
  
  while (current)
    {
      trolley *t = (trolley*)current->box;
      int action = key_compare(t->key, key);

      log_info("get_elem_trolley_aux", current, "%p");
      log_info("get_elem_trolley_aux", t, "%p");
      log_info("get_elem_trolley_aux", action, "%d");
      
      if (action == 0) return current;
      current = current->next;
    }

  return NULL;
}



void destroy_trolley_aux(elem *e)
{
  assert(e);

  if(e->next) destroy_trolley_aux(e->next);
  if(e->box)
    {
      trolley *t = (trolley*)e->box;
      if(t)
	{
	  if(t->key) free(t->key);
	  free(t);
	}
    }

  free(e);
}

void destroy_trolley(list *l)
{
  assert(l);

  if(l->first) destroy_trolley_aux(l->first);
  l->first = NULL;
  l->last = NULL;
  if(l->stuff) free(l->stuff);

  free(l);
}
