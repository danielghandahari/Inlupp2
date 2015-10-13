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

bool check_elem_in_list(list *l, elem *e); 

bool check_elem_in_list(list *l, elem *e); 

int elem_compare(void *e1, void *e2); 


void generate_new_elem();


#endif
