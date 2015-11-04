#include <database.h>
#include <database_secret.h>
#include <trolley_secret.h>
#include <trolley.h>
#include <stdlib.h>
#include <stdbool.h>

trolley * create_trolley()
{
  trolley *t = calloc(1, sizeof(trolley));
  return t;
}


bool trolley_is_empty(list *l)
{
  return l->first ? false : true;
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



void pack_trolley(list *l, char *key, int amount)
{
  elem *e = get_elem_in_list_DB(l, key);

  if(e)
    {
      incr_amount(e, amount);
      incr_trolley_price(l, amount);
    }
  else
    {
      elem *new_elem = create_elem();
      trolley *new_trolley = (trolley*)new_elem->box;

      new_trolley->key = key;
      new_trolley->amount = amount;

      insert_elem_in_list(l, new_elem);
    }
}



void destroy_trolley(list *l)
{
  elem *temp = l->first;

  while(temp)
    {
      trolley *s = (trolley*)temp->box;
      char *t1 = s->key;
      elem *free_temp = temp;

      temp = temp->next;
      
      free(t1);
      free(temp->box);
      free(free_temp);
    }
  free(l->stuff);
  free(l);
}
