#include<stdbool.h>
#include<string.h>
#include<list.h>

struct _list_
{
  void *stuff;

  elem *first;
  elem *last;
};

struct _elem_
{
  void * box;

  elem *next;
};


bool check_elem_in_list(list *l, elem *e)
{
  elem *head = l->first;
  
  while (l->first != NULL)
    {
      int action = elem_compare(l->first->box, e->box);
      
      if (action == 0)
	{
	  l->first = head;
	  return true;
	}
      l->first = l->first->next;
      
    }
  l->first = head;
  return false;
}





void generate_new_elem();



