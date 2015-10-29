#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <list.h>
#include <list_secret.h>

#define Equal action == 0






elem * create_elem()
{
  elem *e = (elem*) calloc(1, sizeof(elem));
  return e;
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




void insert_elem_in_list(list *l, elem *e)
{
  if(l->first == NULL)
    {
      l->first = e;
      l->last = e;
      e->next = NULL;
    }
  else
    {
      l->last->next = e;
      l->last = e;
      e->next = NULL;
    }  
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

