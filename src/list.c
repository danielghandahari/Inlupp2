#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <list.h>

#define Equal action == 0



struct _list_
{
  void *stuff;

  elem *first;
  elem *last;
};

struct _elem_
{
  void *box;

  elem *next;
};


bool check_elem_in_list(list *l, elem *e)
{
  assert(l == NULL);

  elem *current = l->first;

  while (current != NULL)
    {
      int action = elem_compare(current->box, e->box);
      
      if (Equal) return true;
	
      current = current->next;
    }
  return false;
}





void generate_new_elem();



