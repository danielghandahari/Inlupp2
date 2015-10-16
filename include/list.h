#ifndef __LIST__
#define __LIST__

typedef struct _list_ list;
typedef struct _elem_ elem;

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




bool find_elem_in_list(list *l, void *elembox);

elem *get_elem(elem *e, void *elembox);

elem * get_elem_in_list(list *l, void *elembox); 




int elem_compare(void *e1, void *e2); 







//FÖR REMOVE_ITEM


void rem_elem_in_list(list *l, void *elembox);

void  rem_elem(elem *e, void *elembox);

#endif
