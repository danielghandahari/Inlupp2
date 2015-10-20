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







void rem_elem_in_list(list *l, void *elembox)
{
  rem_elem(l->first, elembox);
}


//GÖR KLART EFTER DU GJORT TIMS FUNKTIONER

/*void rem_elem(elem *e, void *elembox)
{
  elem *temp = get_elem(e, elembox);
    
  }*/




void insert_elem_in_list(list *l, void *elembox);
