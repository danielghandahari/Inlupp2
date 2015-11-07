#include <dbg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <list.h>
#include <database_secret.h>
#include <list_secret.h>

typedef struct _shelf_ shelf;

#define Equal action == 0






elem * create_elem()
{
  elem *e = (elem*) calloc(1, sizeof(elem));
  return e;
}

elem * get_first_elem(list *l)
{
  return l->first;
}



list * create_list()
{
  list *l = (list*) calloc(1, sizeof(list));
  return l;
}

bool find_elem_in_list(list *l, void *elembox)
{
  return get_elem_in_list(l, elembox);
}



elem * get_elem_in_list(list *l, void *elembox)
{
  return get_elem(l->first, elembox);
}

elem * get_elem(elem *e, void *elembox)
{
  elem *current = e;

  while (current)
    {
      int action = elem_compare(current->box, elembox);
      
      if (Equal) return current;
      current = current->next;
    }
  return NULL;
}


void insert_elem_in_list_aux(elem **e, elem *ins_e)
{
  shelf* s = (shelf*)(*e)->box;
  shelf* ins_s = (shelf*) ins_e->box;

  if(s->amount < ins_s->amount)
    {
      ins_e->next = (*e)->next;
      (*e) = ins_e;
    }
  
  if((*e)->next) insert_elem_in_list_aux(&(*e)->next, ins_e);
  else (*e)->next = ins_e;
}

void insert_elem_in_list(list *l, elem *e)
{
  if(l->first == NULL)
    {
      l->first = e;
      l->last = e;
      e->next = NULL;
    }
  else insert_elem_in_list_aux(&(l->first), e);
}



elem * get_last_elem(elem **e)
{
  elem *temp = *e;

  while(temp)
    {
      temp = temp->next;
    }
  return temp;
}

