#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <list.h>

#define Equal action == 0



bool find_elem_in_list(list *l, void *elembox)
{
  return get_elem_in_list(l, elembox);
}



elem * get_elem_in_list(list *l, void *elembox)
{
  return  get_elem(l->first, elembox);
}

elem * get_elem(elem *e, void *elembox)
{
  while (e)
    {
      int action = elem_compare(e->box, elembox);
      
      if (Equal) return e;
      e = e->next;
    }
  return NULL;
}







void rem_elem_in_list(list *l, void *elembox)
{
  rem_elem(l->first, elembox);
}

void rem_elem(elem *e, void *elembox)
{
  elem *myelem = get_elem(e, elembox);
    
}




