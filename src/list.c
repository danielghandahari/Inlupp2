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

  while (e)
    {
      int action = elem_compare(current->box, elembox);
      
      if (Equal) return current;
      current = current->next;
    }
  return NULL;
}







/*void rem_elem_in_list(list *l, void *elembox)
{
  rem_elem(l->first, elembox);
}*/


//GÖR KLART EFTER DU GJORT TIMS FUNKTIONER

/*void rem_elem(elem *e, void *elembox)
{
  elem *temp = get_elem(e, elembox);
    
  }*/




void insert_elem_in_list(list *l, elem *e)
{
  if(l->first == NULL)
    {
      l->first = e;
      l->last = e;
    }
  if(l->first)
    {
      elem *lastelem = get_last_elem(l);

      lastelem->next = e;
      l->last = e;
    }
}



elem * get_last_elem(list *l)
{
  elem *temp = l->first;

  while(!temp)
    {
      temp = temp->next;
    }
  return temp;
}
